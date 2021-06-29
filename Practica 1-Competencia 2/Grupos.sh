#!/bin/bash
ACEPTADO=0
clear
echo "-*-*-*-*-Menu-*-*-*-*-"
echo "1. Ingresar Usuarios"
echo "2. Eliminar Usuarios"
echo "3. Ingresar Grupos"
echo "4. Eliminar Grupos"
echo "-*-*-*-*-*-*-*-*-*-*-*-"



read opcion
case $opcion in

1)
echo "Escriba el Nombre del Usuario: "; sleep 1; read nombre

sudo useradd -d /home/$nombre -m -s /bin/bash $nombre
passwd $nombre
if [ $? -eq $ACEPTADO ]
then
echo "Usuario Creado, Gracias"
else 
echo "no se pudo crear el usuario"
fi
;;

2)
echo "Escriba el Nombre del Usuario a Eliminar: "; sleep 1; read nombre

sudo userdel -r $nombre

if [ $? -eq $ACEPTADO ]
then
echo "Usuario Eliminado, Gracias"
else 
echo "no se pudo eliminar el usuario"
fi
;;
3)
if [ $? -eq $ACEPTADO ]
echo "Introduce el nombre del grupo:"; sleep 1; read grupos

sudo groupadd $grupos
then
echo "Grupo Creado Exitosamente"
else
echo "no se pudo crear el grupo"
fi
;;

4)
if [ $? -eq $ACEPTADO ]
echo "Introduce el nombre del grupo que eliminaras:"; sleep 1; read grupo

sudo delgroup $grupo
then
echo "Grupo Eliminado Exitosamente"
else
echo "no se pudo Eliminar el grupo"
fi
;;
esac
echo "Desea realizar otra opcion?"
echo "si"
echo "no"

read opcion
case $opcion in

si) ./Grupos.sh;;
no) clear;;
esac
sleep 2
echo "Saliendo..."
