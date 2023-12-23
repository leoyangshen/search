AWS Academy module 13 optional guided lab
On dockerhub leoyangshen/mb-xxxxx-repo

1. Install npm, the node package manager, and it will install dependent packages node-js and others
 dnf install npm
2. Change into 1-no-container directory and install modules by running
 npm install koa
 npm install koa-router
3. Start the message board application
 npm start # start is defined in package.json as node index.js
4. Test the RESTful invocation by issuing
 curl localhost:3000/api/users
5. Test to retrieve the forth user Jake
 curl localhost:3000/api/users/4
6. Test to retrieve all threads in the database
 curl localhost:3000/api/threads
7. Retrieve all the posts for the first thread in the database
 curl localhost:3000/api/posts/in-thread/1
   Test other RESTful API methods
 curl localhost:3000/
 curl localhost:3000/api

8. Change into 2-containerized-monolith and build docker image
 docker build -t mb-repo .
9. Run it
 docker run mb-repo
10.Find its address and port
 docker ps # To see its GIVEN-NAME
 docker inspect GIVEN-NAME # To see its address like 172.17.0.2
11.Try it
 curl 172.17.0.2:3000/

12.Change into 3-containerized-microservices and build docker images 
 and change into users directory
13.Build the user micro service
 docker build -t mb-users-repo .
14.Change into threads directory and build image for threads
 docker build -t mb-threads-repo .
15.Change into posts directory and build image for posts
 docker build -t mb-posts-repo .
16.Start all three individual containers and query them seperately, such as
 docker run mb-users-repo, mb-posts-repo and mb-threads-repo
 curl 172.17.0.2:3000/, 172.17.0.3:3000/index, 172.17.0.4:3000/users

The RESTful API's are as follows:
GET /api/users: Returns the collection of users in the database
GET /api/users/:userId: Returns the information for the user that is identified by :userId
GET /api/threads: Returns the collection of threads in the database
GET /api/threads/:threadId: Returns the information for the thread that is identified by :threadId
GET /api/posts/in-thread/:threadId: Returns the collection of post messages for the thread that is identified by :threadId
GET /api/posts/by-user/:userId: Returns the collection of post messages for the user that is identified by :userId
GET /api/: Returns the message API ready to receive requests
GET /: Returns the message Ready to receive requests

17.Tag the image for pushing to remote repository
 docker login
 docker tag mb-repo leoyangshen/mb-repo
 docker push leoyangshen/mb-repo
