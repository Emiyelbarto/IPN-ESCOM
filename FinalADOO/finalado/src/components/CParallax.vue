<template>
  <div>
    <v-parallax src="@/assets/pictures/bg-4.jpg" dark>
      <v-row align="end" justify="end">
        <v-col class="text-end" cols="12">
          <h1 class="display-1 font-weight-thin mb-4">
            Una nueva forma de ver streamings.
          </h1>
          <h4 class="subheading">
            Gracias a la integración con Twitch, e-sports Hub brinda los
            streamings más famosos
          </h4>
          <h4 class="subheading">
            a la plataforma para evitar el uso de páginas externas y busquedas
            innecesarias
          </h4>
          <h4 class="subheading">
            ahorrando tiempo de busqueda y transformándolo en tiempo de visión.
          </h4>
        </v-col>
        <v-col class="text-end">
          <iframe
            src="https://player.twitch.tv/?video=v367046564&autoplay=true"
            height="300px"
            width="40%"
            frameborder="<frameborder>"
            scrolling="<scrolling>"
            allowfullscreen="<allowfullscreen>"
            autoplay="true"
          />
        </v-col>
      </v-row>
    </v-parallax>
  </div>
</template>

<script>
export default {
  data() {
    return {};
  },
  components: {}
};
</script>

<style lang="css">
.v-parallax {
  size: 100% 100%;
}
</style>
