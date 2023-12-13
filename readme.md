# Trabajo práctico número 4 (TP4)
## Antecedentes generales

*Autor:* Luis Gómez P

**Docente:**

**Motivo:** como parte del Trabajo Práctico  del ramo de ingeniería de software

**Ojetivo:** Configurar un entorno productivo para la generación de Código en C utilizando herramientas como GitHub, Doxygen, clang-format, pre-commit y makefile.

Completar las tareas habituales al realizar cambios en un repositorio GIT compartido.
Documentar las funciones con Doxygen. Modificar un archivo makefile existente agregando
una nueva regla

En este caso particular también se configuraran algunas herramientas en emacs.

## Entregables

Los entregables requeridos son:
1. Commit con la resolución de un conflicto en la rama master del repositorio compartido
por la cátedra.
2. Repositorio privado derivado mediante un fork del repositorio de la cátedra con el
código fuente documentado usando doxygen y una regla en el archivo makefile que
genere toda la documentación del proyecto.
3. Pull request para volcar los cambios de la rama develop del repositorio privado en la
rama develop de repositorio de la cátedra.


## Construcción de gitignore

l archivo .gitignore es una herramienta esencial en el sistema de control de versiones Git. Permite a los desarrolladores especificar qué archivos y directorios deben ser ignorados por Git y no ser rastreados en el repositorio. Esto es útil para evitar que archivos temporales, de compilación o sensibles se incluyan accidentalmente en el historial de cambios, manteniendo el repositorio limpio y organizado.

Una herramienta para generar el archivo .gitignore de manera  personalizada de acuerdo   a las necesidades del usuario es:

https://www.toptal.com/developers/gitignore/

En esta página puedes incluir el lenguaje en el que trabajaras y la IDE por ejemplo.



## Clang-Format

Este repositorio utiliza pre-commit para validaciones de formato. Para trabajar con el mismo usted debería tener instalado:

   1. pre-commit (https://pre-commit.com/#install)
   2. cpp-check (https://cppcheck.sourceforge.io)

Después de clonar el repositorio usted debería ejecutar el siguiente comando:


```
pre-commit install
```
Para generar la documentación del proyecto se utiliza el siguiente comando:

```
make doc
```



```
make all
```
