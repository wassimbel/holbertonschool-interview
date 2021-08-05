#!/usr/bin/node
const request = require('request');

function getNames (chars) {
  return new Promise(function (resolve, reject) {
    request(chars, function (error, response, body) {
      if (error) {
        reject(error);
      } else {
        resolve(JSON.parse(body).name);
      }
    });
  });
}

request(`https://swapi-api.hbtn.io/api/films/${process.argv[2]}`,
  async function (error, response, body) {
    if (error) {
      console.log(error);
    } else {
      const names = JSON.parse(body).characters;
      for (let i = 0; i < names.length; i++) {
        const name = await getNames(names[i]);
        console.log(name);
      }
    }
  });
