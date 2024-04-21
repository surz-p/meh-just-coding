// ==UserScript==
// @name         End Card Removal
// @namespace    http://tampermonkey.net/
// @version      1.0.2
// @description  try to take over the world! (yeah why not)
// @author       Surz P
// @match        https://www.youtube.com/*
// @icon         https://www.google.com/s2/favicons?sz=64&domain=stackoverflow.com
// @grant        none
// ==/UserScript==

// Tapermonkey snippet that I wrote to remove the end card elements from youtube videos

(function() {
    'use strict';

    setInterval(() => {
        let allElements = document.getElementsByTagName('*');
        let regex = /ytp-ce-element/;
        let elementsToRemove = [];

        for (var i = 0; i < allElements.length; i++) {
            let element = allElements[i];

            let classAttr = element.getAttribute('class');

            if (classAttr && classAttr.match(regex)) {
                console.log('Removed: ', element);
                elementsToRemove.push(element);
            }
        }

        elementsToRemove.forEach(element => element.remove());
    }, 10000);
})();
