Inception

Overview

Inception is a system administration project focused on using Docker to virtualize various services. You'll create a personal virtual machine with several Docker images, setting up a small infrastructure of interconnected services.

Goals

The objectives of the Inception project are to:

- Gain hands-on experience with Docker and system administration.
- Learn to create and manage Docker containers and images.
- Implement and configure multiple services in a Docker environment.
- Adhere to best practices for writing Dockerfiles and managing Docker networks.

Features

- Setup of multiple Docker containers with specific services:
  - NGINX with TLSv1.2 or TLSv1.3
  - WordPress with php-fpm
  - MariaDB
- Volume management for WordPress database and website files.
- Docker networking to connect containers.
- Automatic container restart in case of crashes.
- Domain name configuration pointing to your local IP.
