FROM nginx:latest
COPY index.html /user/share/nginx/html/ 
EXPOSE 80
CMD ["nginx","-g","daemon off;"]