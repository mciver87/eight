// Initialize DENR Org Chart
var orgChartSrc = $('#denr-org-chart-source'),
    orgChart = $('#denr-org-chart');

if (orgChart.length) {
    $(window).load(function () {
        var default_photo = '../img/p_org-chart-default.png';
        var options = new primitives.orgdiagram.Config();

        var items = [
            new primitives.orgdiagram.ItemConfig({
                id: 0,
                parent: null,
                title: "Donald R. van der Vaart",
                description: "Secretary, Department of Environmental & Natural Resources",
                //image: default_photo,
                itemTitleColor: '#092940',
                templateName: "level-0-template"
            }),
            new primitives.orgdiagram.ItemConfig({
                id: 1,
                parent: 0,
                title: "Dorothy Harris",
                description: "Executive Assistant",
                //image: default_photo,
                itemTitleColor: '#588023',
                itemType: primitives.orgdiagram.ItemType.SubAssistant,
                adviserPlacementType: primitives.common.AdviserPlacementType.Left,
                templateName: "default-template"
            }),
            new primitives.orgdiagram.ItemConfig({
                id: 2,
                parent: 0,
                title: "Crystal Feldman",
                description: "Communications Director",
                //image: default_photo,
                itemTitleColor: '#588023',
                itemType: primitives.orgdiagram.ItemType.SubAssistant,
                adviserPlacementType: primitives.common.AdviserPlacementType.Left,
                templateName: "default-template"
            }),
            new primitives.orgdiagram.ItemConfig({
                id: 3,
                parent: 0,
                title: "Rita Richardson",
                description: "Human Resources",
                //image: default_photo,
                itemTitleColor: '#588023',
                itemType: primitives.orgdiagram.ItemType.SubAssistant,
                adviserPlacementType: primitives.common.AdviserPlacementType.Left,
                templateName: "default-template"
            }),
            new primitives.orgdiagram.ItemConfig({
                id: 4,
                parent: 0,
                title: "Matthew Dockham",
                description: "Legislative Affairs",
                //image: default_photo,
                itemTitleColor: '#588023',
                itemType: primitives.orgdiagram.ItemType.SubAssistant,
                adviserPlacementType: primitives.common.AdviserPlacementType.Left,
                templateName: "default-template"
            }),
            new primitives.orgdiagram.ItemConfig({
                id: 5,
                parent: 0,
                title: "John C. Evans",
                description: "Chief Deputy Secretary",
                //image: default_photo,
                itemTitleColor: '#00376D',
                templateName: "default-template"
            }),
            new primitives.orgdiagram.ItemConfig({
                id: 6,
                parent: 0,
                title: "Sam M. Hayes",
                description: "General Counsel",
                //image: default_photo,
                itemTitleColor: '#588023',
                itemType: primitives.orgdiagram.ItemType.SubAssistant,
                adviserPlacementType: primitives.common.AdviserPlacementType.Right,
                templateName: "default-template"
            }),
            new primitives.orgdiagram.ItemConfig({
                id: 7,
                parent: 0,
                title: "Rex Whaley",
                description: "Chief Financial Officer",
                //image: default_photo,
                itemTitleColor: '#588023',
                itemType: primitives.orgdiagram.ItemType.SubAssistant,
                adviserPlacementType: primitives.common.AdviserPlacementType.Right,
                templateName: "default-template"
            }),
            new primitives.orgdiagram.ItemConfig({
                id: 8,
                parent: 5,
                title: "Ted Bush",
                description: "Env. Assist. & Customer Srv.",
                //image: default_photo,
                itemTitleColor: '#397AAC',
                templateName: "default-template"
            }),
            new primitives.orgdiagram.ItemConfig({
                id: 9,
                parent: 5,
                title: "Vacant",
                description: "Asst. Secretary, Natural Resources",
                //image: default_photo,
                itemTitleColor: '#397AAC',
                childrenPlacementType: primitives.common.ChildrenPlacementType.Matrix,
                templateName: "vacant-template"
            }),
            new primitives.orgdiagram.ItemConfig({
                id: 10,
                parent: 5,
                title: "Tom Reeder",
                description: "Asst. Secretary, Environment",
                //image: default_photo,
                itemTitleColor: '#397AAC',
                childrenPlacementType: primitives.common.ChildrenPlacementType.Matrix,
                templateName: "default-template"
            }),
            new primitives.orgdiagram.ItemConfig({
                id: 11,
                parent: 5,
                title: "Vacant",
                description: "Internal Audit",
                //image: default_photo,
                itemTitleColor: '#397AAC',
                templateName: "vacant-template"
            }),
            new primitives.orgdiagram.ItemConfig({
                id: 12,
                parent: 5,
                title: "Jenny Kelvington",
                description: "Energy Policy Advisor",
                //image: default_photo,
                itemTitleColor: '#397AAC',
                templateName: "default-template"
            }),
            new primitives.orgdiagram.ItemConfig({
                id: 13,
                parent: 5,
                title: "Keith Werner",
                description: "Chief Information Officer",
                //image: default_photo,
                itemTitleColor: '#397AAC',
                templateName: "default-template"
            }),
            new primitives.orgdiagram.ItemConfig({
                id: 14,
                parent: 9,
                title: "David Griffin",
                description: "Aquariums",
                //image: default_photo,
                itemTitleColor: '#6A7681',
                templateName: "default-template"
            }),
            new primitives.orgdiagram.ItemConfig({
                id: 15,
                parent: 9,
                title: "Louis Daniel",
                description: "Marine Fishieries",
                //image: default_photo,
                itemTitleColor: '#6A7681',
                templateName: "default-template"
            }),
            new primitives.orgdiagram.ItemConfig({
                id: 16,
                parent: 9,
                title: "Emlyn Koster",
                description: "Museum of Natural Sciences",
                //image: default_photo,
                itemTitleColor: '#6A7681',
                templateName: "default-template"
            }),
            new primitives.orgdiagram.ItemConfig({
                id: 17,
                parent: 9,
                title: "Michael Murphy",
                description: "Parks & Recreation",
                //image: default_photo,
                itemTitleColor: '#6A7681',
                templateName: "default-template"
            }),
            new primitives.orgdiagram.ItemConfig({
                id: 18,
                parent: 9,
                title: "David Jones",
                description: "NC Zoo",
                //image: default_photo,
                itemTitleColor: '#6A7681',
                templateName: "default-template"
            }),
            new primitives.orgdiagram.ItemConfig({
                id: 19,
                parent: 10,
                title: "Sheila Holman",
                description: "Air Quality",
                //image: default_photo,
                itemTitleColor: '#6A7681',
                templateName: "default-template"
            }),
            new primitives.orgdiagram.ItemConfig({
                id: 20,
                parent: 10,
                title: "Braxton Davis",
                description: "Coastal Management",
                //image: default_photo,
                itemTitleColor: '#6A7681',
                templateName: "default-template"
            }),
            new primitives.orgdiagram.ItemConfig({
                id: 21,
                parent: 10,
                title: "Tracy Davis",
                description: "Energy, Mineral & Land Resources",
                //image: default_photo,
                itemTitleColor: '#6A7681',
                templateName: "default-template"
            }),
            new primitives.orgdiagram.ItemConfig({
                id: 22,
                parent: 10,
                title: "Michael Ellison",
                description: "Mitigation Services",
                //image: default_photo,
                itemTitleColor: '#6A7681',
                templateName: "default-template"
            }),
            new primitives.orgdiagram.ItemConfig({
                id: 23,
                parent: 10,
                title: "Linda Culpepper",
                description: "Waste Management",
                //image: default_photo,
                itemTitleColor: '#6A7681',
                templateName: "default-template"
            }),
            new primitives.orgdiagram.ItemConfig({
                id: 24,
                parent: 10,
                title: "Kim Colson",
                description: "Water Infrastructure",
                //image: default_photo,
                itemTitleColor: '#6A7681',
                templateName: "default-template"
            }),
            new primitives.orgdiagram.ItemConfig({
                id: 25,
                parent: 10,
                title: "Jay Zimmerman",
                description: "Water Resources",
                //image: default_photo,
                itemTitleColor: '#6A7681',
                templateName: "default-template"
            })
        ];

        options.items = items;
        options.cursorItem = 0;
        options.templates = [getLevel0Template(), getDefaultTemplate(), getVacantTemplate()];
        options.onItemRender = onTemplateRender;
        options.hasSelectorCheckbox = primitives.common.Enabled.False;

        // Declare the diagram
        orgChart.orgDiagram(options);
        
        function onTemplateRender(event, data) {
            switch (data.renderingMode) {
                case primitives.common.RenderingMode.Create:
                    /* Initialize widgets here */
                    break;
                case primitives.common.RenderingMode.Update:
                    /* Update widgets here */
                    break;
            }

            var itemConfig = data.context;

            if (data.templateName == "default-template") {
                //data.element.find("[name=photo]").attr({ "src": itemConfig.image, "alt": itemConfig.title });
                data.element.find("[name=titleBackground]").css({ "background": itemConfig.itemTitleColor });
                data.element.find("[name=title]").attr('title', itemConfig.title);

                var fields = ["title", "description"];
                for (var index = 0; index < fields.length; index++) {
                    var field = fields[index];

                    var element = data.element.find("[name=" + field + "]");
                    if (element.text() != itemConfig[field]) {
                        element.text(itemConfig[field]);
                    }
                }
            } else if (data.templateName == "level-0-template") {
                //data.element.find("[name=photo]").attr({ "src": itemConfig.image, "alt": itemConfig.title });
                data.element.find("[name=titleBackground]").css({ "background": itemConfig.itemTitleColor });
                data.element.find("[name=title]").attr('title', itemConfig.title);

                var fields = ["title", "description"];
                for (var index = 0; index < fields.length; index++) {
                    var field = fields[index];

                    var element = data.element.find("[name=" + field + "]");
                    if (element.text() != itemConfig[field]) {
                        element.text(itemConfig[field]);
                    }
                }
            } else if (data.templateName == "vacant-template") {
                //data.element.find("[name=photo]").attr({ "src": itemConfig.image, "alt": itemConfig.title });
                data.element.find("[name=titleBackground]").css({ "background": itemConfig.itemTitleColor });
                data.element.find("[name=title]").attr('title', itemConfig.title);

                var fields = ["title", "description"];
                for (var index = 0; index < fields.length; index++) {
                    var field = fields[index];

                    var element = data.element.find("[name=" + field + "]");
                    if (element.text() != itemConfig[field]) {
                        element.text(itemConfig[field]);
                    }
                }
            }
        }

        // Template -- Level 0
        function getLevel0Template() {
            var result = new primitives.orgdiagram.TemplateConfig();
            result.name = "level-0-template";
            result.itemSize = new primitives.common.Size(210, 100);
            result.itemBorderWidth = 0;
            result.minimizedItemSize = new primitives.common.Size(3, 3);
            result.highlightPadding = new primitives.common.Thickness(0, 0, 0, 0);
            result.cursorPadding = new primitives.common.Thickness(0, 0, 0, 0);

            var itemTemplate = jQuery(
              '<div class="bp-item level-0">'
                + '<div name="titleBackground">'
                    + '<div name="title" class="bp-title">'
                    + '</div>'
                + '</div>'
                //+ '<div class="bp-photo-frame">'
                //    + '<img name="photo" />'
                //+ '</div>'
                + '<div name="description" class="bp-description"></div>'
            + '</div>'
            ).css({
                width: result.itemSize.width + "px",
                height: result.itemSize.height + "px"
            }).addClass("bp-item bt-item-frame");
            result.itemTemplate = itemTemplate.wrap('<div>').parent().html();

            return result;
        }

        // Template -- Default
        function getDefaultTemplate() {
            var result = new primitives.orgdiagram.TemplateConfig();
            result.name = "default-template";
            result.itemSize = new primitives.common.Size(120, 100);
            result.minimizedItemSize = new primitives.common.Size(3, 3);
            result.highlightPadding = new primitives.common.Thickness(0, 0, 0, 0);
            result.cursorPadding = new primitives.common.Thickness(0, 0, 0, 0);

            var itemTemplate = jQuery(
              '<div class="bp-item">'
                + '<div name="titleBackground">'
                    + '<div name="title" class="bp-title">'
                    + '</div>'
                + '</div>'
                //+ '<div class="bp-photo-frame">'
                //    + '<img name="photo" />'
                //+ '</div>'
                + '<div name="description" class="bp-description"></div>'
            + '</div>'
            ).css({
                width: result.itemSize.width + "px",
                height: result.itemSize.height + "px"
            }).addClass("bp-item bt-item-frame");
            result.itemTemplate = itemTemplate.wrap('<div>').parent().html();

            return result;
        }

        // Template -- Default
        function getVacantTemplate() {
            var result = new primitives.orgdiagram.TemplateConfig();
            result.name = "vacant-template";
            result.itemSize = new primitives.common.Size(120, 100);
            result.minimizedItemSize = new primitives.common.Size(3, 3);
            result.highlightPadding = new primitives.common.Thickness(0, 0, 0, 0);
            result.cursorPadding = new primitives.common.Thickness(0, 0, 0, 0);

            var itemTemplate = jQuery(
              '<div class="bp-item vacant">'
                + '<div name="titleBackground">'
                    + '<div name="title" class="bp-title">'
                    + '</div>'
                + '</div>'
                //+ '<div class="bp-photo-frame">'
                //    + '<img name="photo" />'
                //+ '</div>'
                + '<div name="description" class="bp-description"></div>'
            + '</div>'
            ).css({
                width: result.itemSize.width + "px",
                height: result.itemSize.height + "px"
            }).addClass("bp-item bt-item-frame");
            result.itemTemplate = itemTemplate.wrap('<div>').parent().html();

            return result;
        }

    });
}