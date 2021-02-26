<template>
  <v-app>
    <ANavBar />

    <v-content>
      <router-view />
    </v-content>

    <AFooter />
  </v-app>
</template>

<script>
import ANavBar from "@/components/ANavBar.vue";
import AFooter from "@/components/AFooter.vue";

export default {
  name: "App",

  components: {
    ANavBar,
    AFooter
  },

  data: () => ({
    //
  })
};
</script>
