FROM node:14

WORKDIR /backend

RUN echo "alias ll='ls -al'" >> ~/.bashrc

RUN apt-get update \
    && apt-get install less

COPY package*.json ./

RUN npm install

COPY . .

EXPOSE 80

CMD ["npm", "start"]
