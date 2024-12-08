FROM node:18
WORKDIR /app
COPY package.json .
RUN mkdir data
RUN npm install
COPY *.html .
COPY *.js .
EXPOSE 8042
CMD ["node", "server.js"]
