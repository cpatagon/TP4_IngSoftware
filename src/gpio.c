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

/** @file gpio.c
 ** @brief Capa de abstracción para la gestión de puertos digitales
 **/

/* === Headers files inclusions =============================================================== */

#include "gpio.h"
#include <stddef.h>

/* === Macros definitions ====================================================================== */

#ifndef MAX_GPIO_INSTANCES
#define MAX_GPIO_INSTANCES 16
#endif

/* === Private data type declarations ========================================================== */

// gpio_h es una estructura que esta formada por un puerto, un pin, un estado y una salida
//! estructura con los atributos de un puerto digital
struct gpio_h {
    uint8_t port; //!< Número de puerto GPIO
    uint8_t pin;  //!< Pin del puerto GPIO
    bool state;   //!< Estado actual del puerto digital
    bool output;  //!< El puerto está configurado como salida
#ifdef USE_STATIC_MEM
    bool used; //!< l descriptor del puerto está ocupado
#endif
};

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

static gpio_t GpioAllocate(void);

/* === Private function implementation ========================================================= */

/**
 * @brief Asigna una instancia de GPIO de un pool predefinido.
 *
 * Esta función actúa como un equivalente a malloc para estructuras GPIO. Busca en un
 * array estático predefinido la primera instancia que no esté en uso y la asigna para su uso.
 * Este enfoque es útil en sistemas con memoria limitada donde la asignación dinámica
 * (como con malloc) podría ser problemática. Esta función es específica para sistemas
 * que definen USE_STATIC_MEM, permitiendo el uso de memoria estática en lugar de dinámica.
 *
 * @note Esta función es parte de una implementación que usa memoria estática.
 *       Asegúrate de que USE_STATIC_MEM esté definido para habilitar esta función.
 *
 * @return gpio_t Retorna un puntero a una instancia de GPIO si se encuentra una disponible.
 *         Retorna NULL si todas las instancias están en uso.
 */

#ifdef USE_STATIC_MEM
static gpio_t GpioAllocate(void) {
    static struct gpio_h instances[MAX_GPIO_INSTANCES] = {
        0}; //!< eso garantiza que se inicializa en 0

    gpio_t self = NULL;
    for (int index = 0; index < MAX_GPIO_INSTANCES; index++) {
        if (!instances[index].used) {
            self = &instances[index];
            self->used = true;
            break;
        }
    }
    return self;
}
#endif

/* === Public function implementation ========================================================== */

gpio_t GpioCreate(uint8_t port, uint8_t bit) {
    gpio_t self;
#ifdef USE_STATIC_MEM
    self = GpioAllocate();
#else
    self = malloc(sizeof(struct gpio_h));
#endif
    /* estado inicial*/
    if (self) {
        self->port = port;
        self->pin = bit;
        self->output = false;
        self->state = false;
    }

    return self;
}

void GpioSetDirection(gpio_t self, bool output) {
    self->output = output;
}

bool GpioGetDirection(gpio_t self) {
    return self->output;
}

void GpioSetState(gpio_t self, bool state) {
    if (self->output) {
        self->state = state;
    }
}

bool GpioGetState(gpio_t self) {
    return self->state;
}

/* === End of documentation ==================================================================== */
