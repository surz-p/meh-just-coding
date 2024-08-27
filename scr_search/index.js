const axios = require('axios');
const fs = require('fs');

// source url:
// https://scr.indianrailways.gov.in/view_section.jsp?fontColor=black&backgroundColor=LIGHTSTEELBLUE&lang=0&id=0,5,268

// refined url:
// https://scr.indianrailways.gov.in/view_section.jsp?&id=0,5,268

const baseURL = 'https://scr.indianrailways.gov.in/';
const pressReleasesURI = 'view_section.jsp?lang=0&id=0,5,268';
const sourceURL = baseURL + pressReleasesURI;

async function search() {
    let urisToPressReleases;
    let numberPressReleases = 0;

    try {
        const pressReleasesInHTML = await axios.get(sourceURL);

        fs.writeFileSync('raw.output.html', pressReleasesInHTML.data);

        const pressReleasesParsed = pressReleasesInHTML.data.replace(/<script[\s\S]*?<\/script>/gi, '');

        fs.writeFileSync('parsed.output.html', pressReleasesParsed);

        const regexForPressRelease = /"view_detail.jsp\?lang=0.*?"/gi;
        urisToPressReleases = pressReleasesParsed.match(regexForPressRelease);
        numberPressReleases = urisToPressReleases.length;

        urisToPressReleases.forEach((uri, idx) => {
            uri = uri.replaceAll('"', '').replaceAll('&amp;', '&').replaceAll('&lt;', '<').replaceAll('&gt;', '>').replaceAll('&quot;', '"');
            urisToPressReleases[idx] = uri;
        })
        console.log(`Found ${numberPressReleases} press release artciles.`);
    } catch (err) {
        console.log(err);
    }

    try {
        console.log(`Fetching all ${numberPressReleases} press release articles... This may take a while.`);
        const URLToPromisesMap = [];
        const pressReleasesContent = [];
        let chunks = [];

        for (let idx = 0; idx < numberPressReleases; idx++) {
            const uri = urisToPressReleases[idx];
            const pressReleaseContentURL = baseURL + uri;
            URLToPromisesMap.push(pressReleaseContentURL);

            chunks.push(axios.get(pressReleaseContentURL));

            if (chunks.length > 0
                && (idx === numberPressReleases - 1 || idx % 15 === 14)) {
                    pressReleasesContent.push(...await Promise.allSettled(chunks));
                    chunks = [];
            }
        }

        const regexForSearch = /12749/gi;
        let numberSearchResults = 0;

        pressReleasesContent.forEach((article, idx) => {
            if (article.status !== 'fulfilled') {
                console.log(`Fail! ${URLToPromisesMap[idx]}, Reason: ${article.reason}`);
                return;
            }

            const articleContent = article.value.data;
            const isRegexMatched = articleContent.match(regexForSearch);
            if (isRegexMatched) {
                numberSearchResults++;
                console.log(`"${regexForSearch.source}" was found in ${URLToPromisesMap[idx]}`);
            }
        });

        // calculate % positive search results;
        // if this is > 30%, then display a message to refine the search criteria.
        const percPositive = parseFloat((numberSearchResults / numberPressReleases * 100).toFixed(2));
        if (percPositive > 30) {
            const status = `Search matches ${percPositive}% of the press releases.\n`
                + `Try narrowing your search criteria for better results.`;

            console.log('**********************************************************************************');
            console.log(status);
            console.log('**********************************************************************************');
        }

    } catch (err) {
        console.log(err);
    }
}

search();
