/*
@licstart  The following is the entire license notice for the
JavaScript code in this file.

Copyright (C) 1997-2019 by Dimitri van Heesch

This program is free software; you can redistribute it and/or modify
it under the terms of version 2 of the GNU General Public License as published by
the Free Software Foundation

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

@licend  The above is the entire license notice
for the JavaScript code in this file
*/
var menudata = {
    children : [
        {text : "Página principal", url : "index.html"},
        {text : "Páginas relacionadas", url : "pages.html"}, {
            text : "Estructuras de Datos",
            url : "annotated.html",
            children : [
                {text : "Estructura de datos", url : "annotated.html"},
                {text : "Índice de estructura de datos", url : "classes.html"}, {
                    text : "Campos de datos",
                    url : "functions.html",
                    children : [
                        {text : "Todo", url : "functions.html"},
                        {text : "Variables", url : "functions_vars.html"}
                    ]
                }
            ]
        },
        {
            text : "Archivos",
            url : "files.html",
            children : [
                {text : "Lista de archivos", url : "files.html"}, {
                    text : "Globales",
                    url : "globals.html",
                    children : [
                        {text : "Todo", url : "globals.html"},
                        {text : "Funciones", url : "globals_func.html"},
                        {text : "Variables", url : "globals_vars.html"},
                        {text : "typedefs", url : "globals_type.html"},
                        {text : "defines", url : "globals_defs.html"}
                    ]
                }
            ]
        }
    ]
}
