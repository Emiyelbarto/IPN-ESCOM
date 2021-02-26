<template>
  <div class="tablas--contenido">
    <h2>
      Agregar articulo
    </h2>
    <form>
      <br />
      <vs-input v-model="Nombre" class="input" label="Nombre" />
      <vs-input v-model="Descripcion" class="input" label="Descripcion" />
      <vs-input v-model="Precio" class="input" label="Precio" type="number" />
      <vs-input
        v-model="Cantidad"
        class="input"
        label="Cantidad"
        type="number"
      />
      <vs-input v-model="CodigoBarras" class="input" label="Codigo de Barras" />
      <vs-dropdown>
        Lugar de Compra
        <vs-icon icon="expand_more" />
        <vs-dropdown-menu>
          <vs-dropdown-item v-for="(n, index) in 4" :key="index">
            opcion {{ n }}
          </vs-dropdown-item>
        </vs-dropdown-menu>
      </vs-dropdown>
      <vs-select v-model="LugarCompra" label="Lugar de compra" class="input">
      </vs-select>
      <vs-button :active="active == 0" class="btn" @click="active = 0"
        >Guardar</vs-button
      >
    </form>
  </div>
</template>

<script>
import { toFormData } from '~/utils/formData'
export default {
  layout: 'admin',
  data() {
    return {
      Nombre: '',
      Descripcion: '',
      Precio: 0,
      Cantidad: 0,
      CodigoBarras: '',
      LugarCompra: 1
    }
  },
  methods: {
    async save() {
      try {
        const body = {
          nombre: this.Nombre,
          descripcion: this.Descripcion,
          precio: this.Precio,
          cantidad: this.Cantidad,
          codBarra: this.CodigoBarras,
          lugarCompra: this.LugarCompra
        }

        const formData = toFormData(body)
        const { message, status } = await this.saveForm(formData)

        if (status === 422 || status === 500) throw message

        this.$vs.notify({ title: 'Agregado' })
      } catch (error) {
        console.error(error)
      }
    },
    saveForm(body) {
      return this.$store.dispatch('admin/articulo/addData', {
        body
      })
    }
  }
}
</script>
