/**
 * This is an adaptation of a solution for CKEditor stripping empty elements from the WYSIWYG
 * that I found at http://stackoverflow.com/questions/18261198/ckeditor-removing-empty-span-automatically
 *
 * NC-1154: Code disappears in WYSIWYG when toggling in and out of Source Mode
 *
 * CKEditor's default behavior is to strip empty elements, but the empty elements are sometimes
 * used for images/icons or otherwise serve a purpose. So, this will prevent empty tags
 * from getting stripped.
 */
if (CKEDITOR) {
    (function ($, editor) {
        CKEDITOR.config.image_prefillDimensions = false;

        $.each(CKEDITOR.dtd.$removeEmpty, function (i, value) {
            CKEDITOR.dtd.$removeEmpty[i] = false;
        });

        CKEDITOR.on('dialogDefinition', function(ev) {
            var dialogName = ev.data.name;
            var dialogDefinition = ev.data.definition;
            switch (dialogName) {
                // Remove some table options.
                case 'table':
                    dialogDefinition.onShow = function() {
                        this.getContentElement("info", "txtBorder").disable();
                        this.getContentElement("info", "txtCellSpace").disable();
                        this.getContentElement("info", "txtCellPad").disable();
                    };

                    // Get the properties tab reference
                    var infoTab = dialogDefinition.getContents('info');

                    infoTab.get('txtWidth').default = '75%';
                    break;
                // Remove the ftp and news protocols from the options.
                case 'link':
                    var protocol = dialogDefinition.getContents('info').get('protocol');
                    for (var i = 0; i < protocol.items.length; i++) {
                        if (protocol.items[i][0] == 'ftp://‎' || protocol.items[i][0] == 'news://‎') {
                            protocol.items.splice(i, 1);
                            i--;
                        }
                    }
                    break;
                case 'image':
                    dialogDefinition.getContents('info').get('cmbAlign').default = 'left';
                    break;
            }
        });

    })(jQuery, CKEDITOR);
}
