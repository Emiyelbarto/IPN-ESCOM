<template>
  <div class="tablas--contenido">
    <h2>
      Agregar paquete
    </h2>
    <form>
      <br />
      <vs-input v-model="Titulo" class="input" label="Titulo" />
      <vs-input v-model="Descripcion" class="input" label="Descripcion" />
      <vs-input v-model="Precio" class="input" label="Precio" type="number" />
      <vs-input
        v-model="DuracionEstimada"
        class="input"
        label="Duracion estimada"
        type="time"
      />
      <vs-button :active="active == 0" class="btn" @click="active = 0"
        >Guardar</vs-button
      >
    </form>
  </div>
</template>

<script>
export default {
  data: () => ({
    Titulo: '',
    Descripcion: '',
    Precio: 0,
    DuracionEstimada: ''
  })
}
</script>
