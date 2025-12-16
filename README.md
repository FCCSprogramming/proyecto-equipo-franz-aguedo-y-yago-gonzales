<<<<<<< HEAD
# Sistema de Gestión Académica

Proyecto final del curso Fundamentos de Programación (CC112).

El programa está hecho en C++ y funciona por consola. Permite registrar estudiantes, cursos, inscripciones y notas, además de guardar y cargar información usando archivos.

--------------------------------------------------------

## Funciones del programa

El sistema permite:

- Registrar estudiantes
- Registrar cursos
- Inscribir estudiantes a cursos
- Registrar notas
- Calcular promedios
- Mostrar reportes
- Crear un archivo de texto con estudiantes aprobados
- Guardar y cargar datos desde un archivo binario
- Buscar un estudiante usando acceso directo

---

## Organización del código

El proyecto está dividido en varios archivos `.h` y `.cpp` para mantener el código ordenado:

- `Persona` es la clase base
- `Estudiante` hereda de `Persona`
- `Curso` guarda la información de los cursos
- `Sistema` controla todo el programa

----------------------------------------------

## Memoria dinámica

Se usa memoria dinámica con `new` y `delete` para manejar los arreglos de estudiantes, cursos y notas.  
No se utilizó la librería `vector`.

----------------------------------------------------------

## Archivos

- **Archivo de texto**: se genera `aprobados.txt`
- **Archivo binario**: se guarda toda la información del sistema
- Se usa acceso directo (`seekg`) para buscar estudiantes en el archivo binario

---------------------------------------------------------
---
## Cómo compilar y ejecutar

En Windows usando MSYS2:

```bash
make
=======
[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/gDjFIwTM)
>>>>>>> 3fd9b70cce57e3bfd557bfc81212159c1b1faa73
