<template>
  <div class="tablas--contenido">
    <h2>
      Agregar empleado
    </h2>
    <form>
      <br />
      <vs-input v-model="Nombre" class="input" label="Nombre" />
      <vs-input v-model="ApellidoP" class="input" label="Apellido paterno" />
      <vs-input v-model="ApellidoM" class="input" label="Apellido materno" />
      <vs-input v-model="Curp" class="input" label="CURP" />
      <vs-input
        v-model="FechaNacimiento"
        class="input"
        label="Fecha de Nacimiento"
        type="date"
      />
      <vs-input
        v-model="FechaIngreso"
        class="input"
        label="Fecha de Ingreso"
        type="date"
      />
      <vs-input v-model="Usuario" class="input" label="Usuario" />
      <vs-input v-model="Contraseña" class="input" label="Contraseña" />
      <vs-input v-model="Correo" class="input" label="Correo" />
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
    Nombre: '',
    ApellidoP: '',
    ApellidoM: '',
    Curp: '',
    FechaNacimiento: '',
    FechaIngreso: '',
    Usuario: '',
    Contraseña: '',
    Correo: ''
  })
}
</script>
