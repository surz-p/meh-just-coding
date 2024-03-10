FROM node:14

WORKDIR /supernode

COPY package.json /supernode/

RUN npm install

COPY . /supernode/

EXPOSE 80

CMD [ "node", "server.js" ]
