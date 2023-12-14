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


## Código implementado

El conjunto de códigos que se desarrolló  forman parte de una biblioteca en C para la gestión de puertos y pines GPIO (General Purpose Input/Output) en sistemas embebidos. A continuación, se presenta un resumen de su funcionalidad y estructura:

Encabezados (main.h y gpio.h):
- **main.h:** Encabezado para el archivo principal, declarando la función main. (ver [enlace](https://github.com/cpatagon/TP4_IngSoftware/blob/gpio/inc/main.h "enlace main.h")  )
- **gpio.h:** Encabezado para la capa de abstracción de GPIO, con definiciones y declaraciones para manipular puertos GPIO. (ver [enlace](https://github.com/cpatagon/TP4_IngSoftware/blob/gpio/inc/gpio.h "enlace gpio.h"))

Estructuras y Tipos de Datos:
    En gpio.h, se define gpio_t como un puntero a una estructura anónima gpio_h, permitiendo la manipulación de GPIOs sin exponer la estructura interna.

Funciones de Gestión de GPIO:
- Creación y Configuración (gpio.h):
    - **GpioCreate:** Crea una nueva instancia de GPIO.
    - **GpioSetDirection:** Establece la dirección del GPIO (entrada o salida).
    - **GpioGetDirection:** Obtiene la dirección actual de un GPIO.
    - **GpioSetState:** Establece el estado del GPIO (alto o bajo).
    - **GpioGetState:** Obtiene el estado actual del GPIO.
- Gestión de Memoria (archivo anterior):
    - **GpioAllocate:** Función para asignar instancias GPIO de un pool estático, útil en sistemas con memoria limitada.

Implementación del Programa Principal (archivo principal):
- **main:** Función principal que podría estar usando estas funciones GPIO para manipular LEDs u otros componentes de hardware.



## Makefile

Un Makefile es un archivo utilizado por el programa make para automatizar la compilación y construcción de proyectos de software. Contiene reglas y dependencias que especifican cómo compilar y enlazar los archivos fuente. Es ampliamente usado en proyectos de programación, especialmente en C y C++.

Para este proyecto se construyo el siguiente archivo makefile [enlace](https://github.com/cpatagon/TP4_IngSoftware/blob/main/makefile "enlace archivo makefile")

Este Makefile está diseñado para un proyecto de software en C. La estructura del archivo se detalla a continuación:

**Definición de directorios:**

 - **SRC_DIR:** Directorio de los archivos fuente (.c).
 - **INC_DIR:** Directorio de archivos de cabecera (.h).
 - **OUT_DIR:** Directorio de salida para los archivos generados.
 - **OBJ_DIR:** Subdirectorio en OUT_DIR para los archivos objeto (.o).

**Localización de archivos fuente y objeto:**

 - **SRC_FILES:** Encuentra todos los archivos .c en SRC_DIR.
 - **OBJ_FILES:** Convierte las rutas de SRC_FILES a rutas en OBJ_DIR para los archivos .o.

**Meta predeterminada:**

 - **.DEFAULT_GOAL:** Establece all como la meta predeterminada.

**Inclusión de archivos de dependencia:**

 - **-include:** Incluye archivos de dependencia para cada archivo objeto.

**Reglas:**

 - **all:** Enlaza los archivos objeto y genera el ejecutable app.elf en OUT_DIR.
		Regla de patrón para compilar archivos fuente a objetos: Crea OBJ_DIR si no existe, compila cada archivo .c a .o y genera archivos de dependencia.
 - **clean:** Elimina OUT_DIR y su contenido.
 - **doc:** Genera documentación utilizando Doxygen y doxyfile.



## Clang-Format

**clang-format** es una herramienta que automáticamente formatea el código fuente para que cumpla con ciertos estilos y convenciones. Es parte del proyecto LLVM y se utiliza principalmente con lenguajes como C, C++, Objective-C y otros. Facilita la lectura y mantenimiento del código al garantizar un estilo consistente.

Este repositorio utiliza pre-commit para validaciones de formato. Para trabajar con el mismo usted debería tener instalado:

   1. pre-commit (https://pre-commit.com/#install)
   2. cpp-check (https://cppcheck.sourceforge.io)


El archivo empleado fue [enlace](https://github.com/cpatagon/TP4_IngSoftware/blob/main/.clang-format "archivo clang-format")


| Variable                              | Descripción                                                                                        |
|---------------------------------------|----------------------------------------------------------------------------------------------------|
| `BasedOnStyle`                        | Establece el estilo base de formateo. `LLVM` es un estilo predefinido.                             |
| `UseTab`                              | Controla el uso de tabulaciones. `Never` significa no usar tabs para indentar.                     |
| `IndentWidth`                         | Ancho de la indentación en espacios. Aquí, cada nivel de indentación tiene 4 espacios.             |
| `TabWidth`                            | Ancho de tabulación en espacios. Define cuántos espacios se visualizan por tabulación.             |
| `BreakBeforeBraces`                   | Define dónde colocar llaves. `Attach` las coloca en la misma línea que el control de código.       |
| `AllowShortBlocksOnASingleLine`       | Permite bloques cortos en una sola línea. Aquí está desactivado (`false`).                         |
| `AllowShortIfStatementsOnASingleLine` | Permite `if` cortos en una línea. Desactivado (`false`).                                           |
| `AllowShortFunctionsOnASingleLine`    | Permite funciones cortas en una línea. Desactivado (`false`).                                      |
| `AllowShortLambdasOnASingleLine`      | Permite lambdas cortas en una línea. Desactivado (`false`).                                        |
| `SortIncludes`                        | Si `true`, ordena las directivas `#include`. Aquí está desactivado (`false`).                      |
| `IndentCaseLabels`                    | Indenta las etiquetas `case` en los `switch`. Desactivado (`false`).                               |
| `ColumnLimit`                         | Límite de longitud de línea. Aquí está configurado a 100 caracteres.                               |
| `AccessModifierOffset`                | Indentación para modificadores de acceso (`public`, `private`, etc.). `-4` desindentar 4 espacios. |
| `FixNamespaceComments`                | Si `true`, agrega comentarios al final de los espacios de nombres. Desactivado (`false`).          |
| `PointerAlignment`                    | Alineación de punteros. `Middle` alinea el asterisco en el medio (`int* var;`).                    |
| `AlignConsecutiveMacros`              | Alinea macros consecutivos. `AcrossEmptyLines` alinea incluso con líneas vacías intermedias.       |


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
El comando pre-commit run --all-files se utiliza para ejecutar manualmente los hooks definidos en el archivo pre-commit sobre todos los archivos del repositorio, independientemente de si han sido modificados o no. Esto es especialmente útil para realizar comprobaciones o formateos en todo el código antes de realizar un commit.

```
pre-commit run --all-files
```


## Git

Git es un sistema de control de versiones distribuido diseñado para manejar proyectos de cualquier tamaño con velocidad y eficiencia. Permite a los desarrolladores rastrear y gestionar cambios en el código fuente, colaborar en proyectos, y mantener un historial completo y detallado de las modificaciones realizadas.

Los principales comando de git son:


| Comando                   | Descripción                                                     |
|---------------------------|-----------------------------------------------------------------|
| `git init`                | Inicializa un nuevo repositorio de Git.                         |
| `git clone <url>`         | Clona un repositorio desde una URL.                             |
| `git add <archivo>`       | Añade un archivo al área de preparación (staging área).         |
| `git commit -m "mensaje"` | Crea un commit con los archivos en el área de preparación.      |
| `git status`              | Muestra el estado del repositorio (archivos modificados, etc.). |
| `git push`                | Envía los commits al repositorio remoto.                        |
| `git pull`                | Actualiza el repositorio local con los cambios del remoto.      |
| `git branch <nombre>`     | Crea una nueva rama.                                            |
| `git checkout <rama>`     | Cambia a otra rama.                                             |
| `git merge <rama>`        | Fusiona los cambios de una rama en la actual.                   |
| `git log`                 | Muestra el historial de commits.                                |
| `git diff`                | Muestra las diferencias entre commits, ramas, etc.              |
| `git fetch`               | Descarga los cambios del repositorio remoto.                    |
| `git reset`               | Revierte cambios en el repositorio.                             |
| `git rm <archivo>`        | Elimina un archivo del repositorio.                             |
| `git stash`               | Guarda temporalmente cambios no listos para commit.             |

### Construcción de gitignore

El archivo .gitignore es una herramienta en el sistema de control de versiones Git. Permite a los desarrolladores especificar qué archivos y directorios deben ser ignorados por Git y no ser rastreados en el repositorio. Esto es útil para evitar que archivos temporales, de compilación o sensibles se incluyan accidentalmente en el historial de cambios, manteniendo el repositorio limpio y organizado.

Una herramienta para generar el archivo .gitignore de manera  personalizada de acuerdo   a las necesidades del usuario es:

https://www.toptal.com/developers/gitignore/

En esta página puedes incluir el lenguaje en el que trabajaras y la IDE por ejemplo.


el archivo de ejemplo generado se puede encontrar en el siguiente [enlace](https://github.com/cpatagon/TP4_IngSoftware/blob/main/.gitignore "enlace gitignore")



### Crear una nueva rama

Se  creo una nueva rama y cambió a ella utilizando:

``` shell
git checkout -b nombre-ramma
```
Se  reemplazó el nombre-rama con el nombre **gpio**  para la nueva rama.

### Realiza Cambios (si es necesario):

Luego se realizaron  los cambios que necesarios en el código o los archivos.

### Confirma los Cambios:

Y luego fueron guardados con:



``` shell
    git add .
    git commit -m "mensaje de comit"
```

### Sube la Nueva Rama a GitHub:

Sube tu nueva rama al repositorio remoto en GitHub con:

``` shell
    git push origin nombre-rama
```


## Doxyfile

Doxygen es una herramienta de generación de documentación para lenguajes de programación como C, C++, Java, y otros. Analiza el código fuente y los comentarios especiales incrustados para producir documentación detallada en varios formatos. Permite a los desarrolladores crear documentación técnica de manera eficiente y estructurada.

El doxyfile es un archivo de configuración para Doxygen. Contiene diversas opciones para personalizar cómo Doxygen analiza el código fuente y genera la documentación. Los desarrolladores pueden ajustar aspectos como el formato de salida, directorios a incluir o excluir, y cómo se deben interpretar los comentarios en el código. Este archivo es esencial para adaptar Doxygen a las necesidades específicas de un proyecto.

El archivo de configuración empleado de doxyfile lo puedes encontrar en el siguiente [enlace](https://github.com/cpatagon/TP4_IngSoftware/blob/gpio/doxyfile "archivo doxyfile")

La página web generada la puede encontrar en siguiente [enlace](https://github.com/cpatagon/TP4_IngSoftware/blob/gpio/build/doc/html/index.html "enlace web")
