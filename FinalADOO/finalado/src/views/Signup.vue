<template>
  <div id="app" class="login">
    <v-app id="inspire">
      <v-container fill-height class="signup">
        <v-layout align-center justify-center>
          <v-flex xs12 sm8 md8>
            <v-card class="elevation-12">
              <v-toolbar dark color="indigo">
                <v-toolbar-title>Registro</v-toolbar-title>
              </v-toolbar>
              <v-card-text>
                <v-form>
                  <v-alert :value="userExists" color="error" icon="warning"
                    >This user already exists, try a different set of
                    data.</v-alert
                  >
                  <v-text-field
                    prepend-icon="person"
                    name="login"
                    v-model="username"
                    label="Login"
                    :rules="[rules.required]"
                  ></v-text-field>
                  <v-text-field
                    prepend-icon="email"
                    name="email"
                    v-model="email"
                    label="Email"
                    :rules="[rules.required, rules.email]"
                  ></v-text-field>

                  <v-text-field
                    prepend-icon="lock"
                    name="password"
                    label="Password"
                    :rules="[rules.required]"
                    type="password"
                    v-model="password"
                  ></v-text-field>

                  <v-text-field
                    prepend-icon="lock"
                    name="password"
                    label="Confirm Password"
                    :rules="[rules.required]"
                    type="password"
                    v-model="confirm_password"
                    :error="!valid()"
                  ></v-text-field>
                </v-form>
              </v-card-text>
              <v-divider light></v-divider>
              <v-card-actions>
                <v-btn to="/login" round color="black" dark>Login</v-btn>
                <v-spacer></v-spacer>
                <v-btn round color="success" @click.prevent="register()">
                  Register
                  <v-icon>keyboard_arrow_up</v-icon>
                </v-btn>
              </v-card-actions>
            </v-card>
          </v-flex>
        </v-layout>
      </v-container>
    </v-app>
  </div>
</template>

<script>
import firebase from "firebase";
export default {
  name: "signup",
  data: () => ({
    userExists: false,
    username: "",
    email: "",
    password: "",
    confirm_password: "",
    rules: {
      required: value => !!value || "Required",
      email: value => {
        const pattern = /^(([^<>()[\]\\.,;:\s@"]+(\.[^<>()[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
        return pattern.test(value) || "Invalid e-mail.";
      }
    }
  }),
  methods: {
    register() {
      if (this.valid()) {
        firebase
          .auth()
          .createUserWithEmailAndPassword(this.email, this.password)
          .then(
            function(username) {
              alert("Cuenta creada! usuario: " + username);
              var semail = firebase.auth().currentUser;
              semail.sendEmailVerification();
              this.$route.push("/login");
            },
            function(error) {
              alert("Error creando cuenta: " + error.message);
            }
          );
      }
    },
    valid() {
      return this.password === this.confirm_password;
    }
  }
};
</script>
<style lang="scss">
.login {
  background-image: url(https://images.unsplash.com/photo-1542751371-adc38448a05e?ixlib=rb-1.2.1&ixid=eyJhcHBfaWQiOjEyMDd9&auto=format&fit=crop&w=1050&q=80);
  background-size: cover;
}
#inspire {
  background: none;
}
</style>
