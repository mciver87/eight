// browser.js -- Drupal-side frontend js to manage user actions outside of the browser iframe.
// Serves as a go-between for the Drupal server and the node.js server.
(function ($) {
    Drupal.behaviors.ncFileBrowser = {
        attach: function (context, settings) {

            // Helper function to get parameters from the query string.
            function getUrlParam( paramName ) {
                var reParam = new RegExp( '(?:[\?&]|&)' + paramName + '=([^&]+)', 'i' );
                var match = window.location.search.match( reParam );

                return ( match && match.length > 1 ) ? match[1] : null;
            }

            //Open File Browser Button
            $(document).on(
                "click", ".initiate-nc-file-browser", function (e) {
                    $(".current-browser-field").removeClass("current-browser-field");
                    $(this).addClass("current-browser-field")
                    // Only one NC File Browser should be open on a page at a time.
                    window.open(Drupal.settings.basePath + "admin/config/media/nc-file-browser/node-edit", "newwindow", "width=1400, height=700");
                }
            );

            if (!$("body").hasClass("page-user")) {
                // Restores the open file browser button after a fieldgroup with a file is ajax reloaded.
                $(document).ajaxComplete(function () {
                    $(".nc-file-interact").each(function () {
                        if ($(this).find(".initiate-nc-file-browser"). length == 0) {
                            $(this).append("<h4 class='initiate-nc-file-browser button'>Open NC File Browser</h4>");
                        }
                    });
                });
            }

            // Adds button(s) to open the browser to the node edit pages.
            $(".nc-file-interact").each(
                function () {
                    if ($(".nc-file-interact").children(".initiate-nc-file-browser").length == 0) {
                        $(".nc-file-interact").append("<h4 class='initiate-nc-file-browser button'>Open NC File Browser</h4>");
                    }
                }
            );

            // Attach button
            $(document).on(
                "click", ".nc-browser-attach", function (e) {
                    // need the field ID, the file id, have the filename
                    var frame = document.getElementById('nc-file-browser');
                    frame.contentWindow.postMessage('needhighlighted', Drupal.settings.node_endpoint);
                }
            );

            var names = [];

            // browser.js Listens for a response from the iframed file browser during the following three Drupal actions:
            // - 1. Attaching a file to a node -- iframe provides filename and receives FID from Drupal via AJAX (nc_file_browser.module)
            // - 2. Uploading a file -- Performs file_save() in Drupal via AJAX.
            // This saves the file to file_managed AND file_usage DB table (registers as imce).
            // - Note that the DB's file_managed entry is added by file_save()
            // - 3. Deleting a file -- frontend.js (node.js frontend) sends filename to browser.js (drupal js frontend).
            // - 4. Changing a wysiwyg URL value from the popup (image/link insertion).
            // browser.js checks file_usage via AJAX, and returns either a confirm or block message.
            // If a block message, nothing is deleted & the page refreshes with a Drupal Alert informing the user where the file is in use.
            // If a confirm message, the file will be deleted.
            function listenerHandle(event)
            {
                // console.log(event);

                // Upload event -- need to register file(s) in Drupal
                // may need to customize the file objects before sending them to PHP via AJAX...
                if (event.data.files) {

                    var path = event.data.path;
                    var files = [];

                    files.push(path);
                    for (file in event.data.files) {
                        if (event.data.files[file].lastModified) {
                            files.push(event.data.files[file].name.replace(/[^a-z0-9.]/gi, '-'));
                            files.push(event.data.files[file].size);
                        }
                    }

                    $.ajax(
                        {
                            type: 'POST',
                            url: '/admin/config/media/nc-file-browser/ajax',
                            data: {uploads: files},
                            dataType: 'text',
                            success: function (data) {
                                alert('Your upload was successful.');
                            },
                            error: function (response) {
                                // console.log(response);
                            },
                        }
                    );
                }

                if (event.data.deleteFiles) {
                    var path = event.data.path;
                    var deleteFiles = event.data.deleteFiles
                    var deleteFilesURI = [];

                    for (file in deleteFiles) {
                        deleteFiles[file] = 'public://' + deleteFiles[file];
                        deleteFilesURI.push(deleteFiles[file].replace('undefined/', ''));
                    }

                    $.ajax(
                        {
                            type: 'POST',
                            url: '/admin/config/media/nc-file-browser/ajax',
                            data: {delete: deleteFilesURI},
                            dataType: 'text',
                            success: function (data) {
                                var blockStr = "confirm";
                                if (blockStr === data) {
                                    var frame = document.getElementById('nc-file-browser');
                                    frame.contentWindow.postMessage('goDelete', Drupal.settings.node_endpoint);
                                }
                                else {
                                    var frame = document.getElementById('nc-file-browser');
                                    frame.contentWindow.postMessage('noDelete', Drupal.settings.node_endpoint);
                                    var frame = document.getElementById('nc-file-browser');
                                    $(data).insertBefore(frame);
                                    $(document).on(
                                        "click", ".file-notify-close", function (e) {
                                            $(this).parent().parent().parent().remove();
                                        }
                                    );
                                }
                            },
                            error: function (response) {
                                // console.log(response);
                            },
                        }
                    );
                }
                // Attach a file to a node.
                // Currently can only attach one file at a time, otherwise works well.
                // If multiple files are selected, only the first will be attached.

                if (event.data["0"] == "fileAttach" && event.data["1"] !== undefined) {
                    if (window.location.pathname == Drupal.settings.basePath + "admin/config/media/nc-file-browser/node-edit") {
                        window.opener.postMessage([event.data["0"], event.data["1"]], "*");
                        window.close();
                    }

                    // Spaces become +, which will interfere with DB actions unless we take care of them here --
                    var files = 'public://' + decodeURIComponent(event.data["1"].split('+').join(' '));
                    // files = encodeURI(files);
                    // Get the ids of the selected files
                    $.ajax(
                        {
                            type: 'POST',
                            url: '/admin/config/media/nc-file-browser/ajax',
                            data: {name: files},
                            dataType: 'text',
                            success: function (data) {
                                var parsedData = data.split("\"").join("");
                                // Get file id from data field passed by hook_widget_form_alter
                                $(".current-browser-field").parent(".nc-file-interact").find("input").each(function() {
                                    if ($(this).attr("name").indexOf("fid") != -1 && $(this).attr("value") == 0) {
                                        var firstInput = $(this).attr("name");
                                        $("input[name='" + firstInput + "']").val(parsedData);
                                    }
                                });
                                $(".current-browser-field").parent(".nc-file-interact").find("input").each(function() {
                                    if ($(this).attr("name").indexOf("upload_button") != -1) {
                                        var submit = $(this);
                                        $(submit).mousedown();
                                    }
                                });
                            },
                            error: function (response) {
                                // console.log(JSON.parse([response.responseText]));
                            },
                        }
                    );
                }
                // Browse mode communication for CKEditor window.
                if (event.data.url && window.location.pathname == Drupal.settings.basePath + "admin/config/media/nc-file-browser/ckeditor") {
                    var funcNum = getUrlParam("CKEditorFuncNum");
                    window.opener.CKEDITOR.tools.callFunction( funcNum, event.data.url );
                    window.close();
                }
            }

             /**
             * detect IE
             * returns version of IE or false, if browser is not Internet Explorer
             */
             function detectIE() {
              var ua = window.navigator.userAgent;

              var msie = ua.indexOf('MSIE ');
              if (msie > 0) {
                    // IE 10 or older => return version number
                    return parseInt(ua.substring(msie + 5, ua.indexOf('.', msie)), 10);
                  }

                  var trident = ua.indexOf('Trident/');
                  if (trident > 0) {
                    // IE 11 => return version number
                    var rv = ua.indexOf('rv:');
                    return parseInt(ua.substring(rv + 3, ua.indexOf('.', rv)), 10);
                  }

                  var edge = ua.indexOf('Edge/');
                  if (edge > 0) {
                   // Edge (IE 12+) => return version number
                   return parseInt(ua.substring(edge + 5, ua.indexOf('.', edge)), 10);
                 }

                // other browser
                return false;
              }

            var newHandle = function (event) {
                listenerHandle(event);};


            window.addEventListener('message', newHandle);


            if ($("body").hasClass("page-admin-config-media-nc-file-browser-ckeditor") || $("body").hasClass("page-admin-config-media-nc-file-browser-node-edit")) {
                $(".breadcrumb").remove();
                $("#toolbar").remove();
                $("#branding").remove();
                $("#admin-menu").css("display", "none");
                $("#admin-menu-wrapper").remove();
                $("body").css("padding-top", "0px");
            }
            else {
                // Need to only perform this on pages w/ CKEDITOR loaded to avoid reference error.
                if (typeof(CKEDITOR) !== 'undefined') {
                    CKEDITOR.config.filebrowserBrowseUrl = Drupal.settings.basePath + "admin/config/media/nc-file-browser/ckeditor";
                    CKEDITOR.config.filebrowserImageBrowseUrl = Drupal.settings.basePath + "admin/config/media/nc-file-browser/ckeditor";
                    CKEDITOR.config.filebrowserUploadUrl = Drupal.settings.basePath + "admin/config/media/nc-file-browser/ckeditor";
                    CKEDITOR.config.filebrowserImageUploadUrl = Drupal.settings.basePath + "admin/config/media/nc-file-browser/ckeditor";
                }
            }

            // For reference --
            // The imce_filefield native submit handler for AJAX --
            // imce_filefield.submit = function(fieldID, fid) {
            //   $('#' + fieldID + '-imce-filefield-fid').val(fid);
            //   $('#' + fieldID + '-imce-filefield-submit').mousedown();
            // };

        }
    };
}(jQuery));
