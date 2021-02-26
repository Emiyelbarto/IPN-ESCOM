<template>
  <div class="about">
    <v-parallax src="@/assets/pictures/bg-about1.jpg" fixed>
      <v-row align="center" justify="center">
        <v-col class="text-center" cols="12">
          <h1 class="display-4 font-weight-bold mb-4">
            Una nueva forma de vivir los <br />
            e-sports
          </h1>
        </v-col>
      </v-row>
    </v-parallax>
    <section class="py-12 px-12">
      <v-row align="start" justify="space-around">
        <v-img
          src="@/assets/pictures/lollogo.png"
          max-height="400"
          max-width="200"
        />
        <v-img
          src="@/assets/pictures/logopoke.jpeg"
          max-height="400"
          max-width="200"
        />
        <v-img
          src="@/assets/pictures/logoESL.jpeg"
          max-height="400"
          max-width="200"
        />
        <v-img
          src="@/assets/pictures/logodota.jpeg"
          max-height="400"
          max-width="200"
        />
        <v-img
          src="@/assets/pictures/logoover.jpeg"
          max-height="400"
          max-width="200"
        />
      </v-row>
      <v-row align="center" justify="start">
        <v-col class="text-center" cols="4">
          <h4 class="display-1 font-weight-light mb-1">
            Nuestro objetivo es recopilar toda la información disponible en
            linea en una sola página para evitar busquedas innecesarias,
            información anticuada y confuciones a la hora de ver transmisiones
            en vivo.
          </h4>
        </v-col>
        <v-col class="text-center" cols="4">
          <h4 class="display-1 font-weight-light mb-1">
            Nuestra misión es brindar conocimiento de e-sports al mundo,
            mostrando a nuevos públicos diferentes ligas, abriendo el mundo de
            los e-sports al público general y crecer junto con los aficionados
            en el mundo de los deportes electrónicos.
          </h4>
        </v-col>
        <v-col class="text-center" cols="4">
          <h4 class="display-1 font-weight-light mb-1">
            Nuestra visión en ser la página principal de e-sports en el mundo,
            adoptando nuevas tenologías, nuevas ligas, fomentando una buena
            competitividad.
          </h4>
        </v-col>
      </v-row>
    </section>
  </div>
</template>

<script>
//  TODO: Corregir todo el asunto de texto de about
export default {};
</script>

<style></style>
