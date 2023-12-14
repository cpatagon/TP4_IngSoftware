/*
 * Nombre del archivo: mi_archivo.c
 * Descripción: [Breve descripción del archivo]
 * Autor: Luis Gómez P.
 * Derechos de Autor: (C) 2023 [Tu nombre o el de tu organización]
 * Licencia: GNU General Public License v3.0
 *
 * Este programa es software libre: puedes redistribuirlo y/o modificarlo
 * bajo los términos de la Licencia Pública General GNU publicada por
 * la Free Software Foundation, ya sea la versión 3 de la Licencia, o
 * (a tu elección) cualquier versión posterior.
 *
 * Este programa se distribuye con la esperanza de que sea útil,
 * pero SIN NINGUNA GARANTÍA; sin siquiera la garantía implícita
 * de COMERCIABILIDAD o APTITUD PARA UN PROPÓSITO PARTICULAR. Ver la
 * Licencia Pública General GNU para más detalles.
 *
 * Deberías haber recibido una copia de la Licencia Pública General GNU
 * junto con este programa. Si no es así, visita <http://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 *
 */

/** @file main.c
 ** @brief Definición de la función principal del programa
 **/

/* === Headers files inclusions =============================================================== */
#include "main.h"
#include "gpio.h"

/* === Macros definitions ====================================================================== */

#define GPIO_A 1 //!< Identificador para el puerto GPIO A
#define GPIO_B 2 //!< Identificador para el puerto GPIO B
#define PIN_3  3 //!< Identificador para el pin número 3
#define PIN_5  5 //!< Identificador para el pin número 5

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */
/**
 * @brief Realiza un retardo.
 *
 * Esta función está destinada a proporcionar un retardo temporal en la ejecución del programa.
 * Actualmente, el cuerpo de la función está vacío y se debe implementar según los requisitos.
 */
void Delay(void) {
    // Implementación del retardo
}

/* === Public function implementation ========================================================== */

int main(void) {
    gpio_t led_rojo;  // Declaración de la instancia para el LED rojo
    gpio_t led_verde; // Declaración de la instancia para el LED verde

    // Creación e inicialización de los LEDs rojo y verde
    led_rojo = GpioCreate(GPIO_A, PIN_3);
    led_verde = GpioCreate(GPIO_B, PIN_5);

    // Configuración del LED rojo como salida y encendido inicial
    GpioSetDirection(led_rojo, true);
    GpioSetState(led_rojo, true);

    while (1) {
        // Alternar el estado del LED rojo
        GpioSetState(led_rojo, false);
        Delay(); // Retardo para observar el cambio de estado
        GpioSetState(led_rojo, false);
    }

    return 0;
}

/* === End of documentation ==================================================================== */
