<template>
  <div class="log-form">
    <h2>
      Recuperacion de contraseña
    </h2>
    <form>
      <vs-input
        v-model="Correo"
        type="email"
        label="Correo"
        placeholder="Escriba su correo para recurperar su contraseña"
      />
      <vs-button :active="active == 0" class="btn" @click="active = 0"
        >Recuperar contrasena</vs-button
      >
    </form>
  </div>
</template>

<script>
export default {
  data: () => ({
    Correo: ''
  })
}
</script>
