<?php

/**
 * Crawler.

curl -XPUT 'http://elsearchstage-ncits.rhcloud.com/_river/ncgov/_meta' -u w0lfpack:NcG0v4l1f3 -d '
{
    "type" : "web",
    "crawl" : {
        "index" : "ncgov",
        "url" : ["http://www.oshr.nc.gov/"],
        "includeFilter" : ["http://www.oshr.nc.gov/.*"],
        "maxDepth" : 5,
        "maxAccessCount" : 1000,
        "numOfThread" : 5,
        "interval" : 1000,
        "target" : [{
            "pattern" : {
                "url" : "http://www.oshr.nc.gov/.*",
                "mimeType" : "text/html"
            },
            "properties" : {
                "title" : {
                    "text" : "title"
                },
                "type" : {
                    "value" : "site_page"
                },
                "search_api_language" : {
                    "value" : "und"
                },
                "search_api_site_hash" : {
                    "value" : "XXXXXX"
                },
                "status" : {
                    "value" : "1"
                },
                "nid" : {
                    "value" : "0"
                },
                "body:value" : {
                    "text" : "body",
                    "trimSpaces" : true
                }
            }
        }]
    }
}
'

// Stop/delete crawler.
curl -XDELETE 'http://elsearchstage-ncits.rhcloud.com/_river/ncgov/' -u w0lfpack:NcG0v4l1f3

//Delete OSHR content.
curl -XDELETE 'http://elsearchstage-ncits.rhcloud.com/ncgov/ncgov/_query?q=url:*oshr*' -u w0lfpack:NcG0v4l1f3

*/
