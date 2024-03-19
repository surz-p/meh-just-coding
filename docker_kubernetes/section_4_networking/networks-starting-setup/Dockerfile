FROM node:14

WORKDIR /supernode

COPY package.json .

RUN npm install

COPY . .

CMD ["node", "app.js"]