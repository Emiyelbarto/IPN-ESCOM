<template>
  <div class="log-form">
    <h2>
      Ingresar al sistema
    </h2>
    <form>
      <vs-input
        v-model="Usuario"
        label="Usuario"
        placeholder="Escriba su Usuario"
      />
      <vs-input
        v-model="Contraseña"
        type="password"
        label="Contraseña"
        placeholder="Escriba su Contraseña"
      />
      <vs-button :active="active == 0" class="btn" @click="active = 0"
        >Ingresar</vs-button
      >
      <a class="forgot">
        <nuxt-link to="/Login-RecuperarContraseña"
          >Recuperar Contraseña</nuxt-link
        >
      </a>
    </form>
  </div>
</template>

<script>
export default {
  data: () => ({
    Usuario: '',
    Contraseña: ''
  })
}
</script>
