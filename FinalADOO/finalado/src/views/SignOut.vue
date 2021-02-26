<template>
  <div>
    <v-alert type="success">
      Se cerró la sesión
    </v-alert>
  </div>
</template>

<script>
import firebase from "firebase";
export default {
  name: "signout",
  components: {},
  methods: {
    lopout: function() {
      firebase
        .auth()
        .signOut()
        .then(() => {
          this.$router.replace("login");
        });
    }
  }
};
</script>

<style></style>
