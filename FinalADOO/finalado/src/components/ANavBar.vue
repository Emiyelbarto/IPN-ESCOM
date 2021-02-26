<template>
  <nav
    color="transparent"
    flat
    tile
    paddles
    justify-space-around
    align-baseline
  >
    <v-app-bar dark fixed flat app class="indigo" hide-on-scroll>
      <v-app-bar-nav-icon @click="drawer = !drawer" />
      <v-toolbar-title>
        <v-img
          src="@/assets/pictures/logohub2.png"
          v-on:click="redirect_to_main"
          width="50%"
          class="mx-auto"
          color="white"
        />
        <v-spacer></v-spacer>
      </v-toolbar-title>
      <v-text-field hide-details prepend-icon="search" single-line>
      </v-text-field>
      <v-spacer></v-spacer>

      <div class="text-end">
        <v-menu offset-y>
          <template v-slot:activator="{ on }">
            <button v-on="on">
              <v-icon>mdi-account</v-icon>
            </button>
          </template>
          <v-list>
            <v-list-item v-for="(item_deploy, index) in deploy" :key="index">
              <v-list-item-title align-content-space-between>
                <v-btn text small flat :to="item_deploy.route">
                  <v-icon icon>{{ item_deploy.icon }}</v-icon>
                  {{ item_deploy.text }}
                </v-btn>
              </v-list-item-title>
            </v-list-item>
          </v-list>
        </v-menu>
        <v-spacer></v-spacer>
      </div>
    </v-app-bar>

    <v-navigation-drawer v-model="drawer" dark app class="indigo">
      <v-layout column align-center v-for="users in user" :key="users.name">
        <v-flex class="mt-5" router :to="users.route">
          <v-avatar size="100">
            <v-img
              src="@/assets/pictures/userhombre.png"
              v-on:click="redirect_to_main"
              width="50%"
              class="mx-auto"
            ></v-img>
          </v-avatar>
          <p class="white--text subheading mt-2 ">
            {{ users.name }}
          </p>
        </v-flex>
      </v-layout>
      <v-list>
        <v-list-item
          v-for="link in links"
          :key="link.text"
          router
          :to="link.route"
        >
          <v-list-item-action>
            <v-list-item-icon>
              <v-icon class="white--text">{{ link.icon }}</v-icon>
            </v-list-item-icon>
          </v-list-item-action>
          <v-list-item-content>
            <v-list-item-title class="white--text">
              {{ link.text }}
            </v-list-item-title>
          </v-list-item-content>
        </v-list-item>
      </v-list>
    </v-navigation-drawer>
  </nav>
</template>

<script>
export default {
  data() {
    return {
      drawer: false,
      icon_drawer: true,
      links: [
        { icon: "mdi-video", text: "Streamings", route: "/streams" },
        { icon: "mdi-xbox-controller", text: "Torneos", route: "/torneos" },
        { icon: "person", text: "Jugadores", route: "/jugadores" }
      ],
      deploy: [
        {
          icon: "mdi-arrow-right-bold",
          title: "Iniciar Sesión",
          text: "Iniciar Sesión",
          route: "/login"
        },
        {
          icon: "mdi-logout",
          title: "SignOut",
          text: "Cerrar Sesión",
          route: "/signout"
        },
        {
          icon: "mdi-checkbook",
          title: "About",
          text: "About",
          route: "/about"
        }
      ],
      user: [
        {
          name: "EmiElFeroz",
          route: "/profile",
          icon: "<img src='@/assets/avatars/user.png' alt='user.png' />"
        }
      ]
    };
  },
  methods: {
    redirect_to_main() {
      window.location.href = "/";
    },
    sign_out() {
      window.location.href = "/signout";
    },
    redirect_to($route) {
      window.location.href = "http://localhost:8080" + $route;
    }
  }
};
</script>
