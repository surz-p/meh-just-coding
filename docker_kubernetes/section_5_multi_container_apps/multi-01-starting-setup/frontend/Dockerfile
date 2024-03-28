FROM node:14

WORKDIR /frontend

RUN echo "alias ll='ls -al'" >> ~/.bashrc

RUN apt-get update \
    && apt-get install less

COPY package*.json ./

RUN npm install

COPY . .

EXPOSE 3000

CMD ["npm", "start"]
