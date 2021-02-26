<template>
  <div class="tablas--contenido">
    <h2>
      Agregar lugar de compra
    </h2>
    <form>
      <br />
      <vs-input
        v-model="NombreTienda"
        class="input"
        label="Nombre de la tienda"
      />
      <vs-input v-model="Direccion" class="input" label="Direccion" />
      <vs-button :active="active == 0" class="btn" @click="active = 0"
        >Guardar</vs-button
      >
    </form>
  </div>
</template>

<script>
export default {
  layout: 'admin',
  data: () => ({
    NombreTienda: '',
    Direccion: ''
  })
}
</script>
