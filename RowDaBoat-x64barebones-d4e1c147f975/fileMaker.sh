docker start CONTAINER 
docker exec -it CONTAINER make clean -C/root/Toolchain 
docker exec -it CONTAINER make clean -C/root/ 
docker exec -it CONTAINER make -C/root/Toolchain 
docker exec -it CONTAINER make -C/root/ 
docker stop CONTAINER
