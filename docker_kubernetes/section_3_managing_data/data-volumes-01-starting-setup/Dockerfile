FROM node:14

WORKDIR /supernode

COPY package.json /supernode/

RUN npm install

COPY . /supernode/

ARG DEFAULT_PORT=80

ENV PORT=$DEFAULT_PORT

EXPOSE $PORT

CMD [ "npm", "start" ]
