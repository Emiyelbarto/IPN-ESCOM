import Vue from "vue";
import Router from "vue-router";
import Home from "@/views/Home.vue";
import Login from "@/views/Login.vue";
import Signup from "@/views/Signup.vue";
import Profile from "@/pages/Profile.vue";
import About from "@/views/About.vue";
import Streamings from "./views/Streamings.vue";
import Torneos from "./views/Torneos.vue";
import Jugadores from "./views/Jugadores.vue";
import Configuration from "./views/Configuration.vue";
import SignOut from "./views/SignOut.vue";

Vue.use(Router);

export default new Router({
    mode: "history",
    routes: [{
            path: "",
            name: "home",
            component: Home,
        },
        {
            path: "/about",
            name: "about",
            component: About
        },
        {
            path: "/login",
            name: "login",
            component: Login
        },
        {
            path: "/index",
            name: "index",
            component: Home
        },
        {
            path: "/streams",
            name: "stream",
            component: Streamings
        },
        {
            path: "/torneos",
            name: "torneos",
            component: Torneos
        },
        {
            path: "/jugadores",
            name: "jugadores",
            component: Jugadores
        },
        {
            path: "/signup",
            name: "signup",
            component: Signup
        },
        {
            path: "/configuration",
            name: "configuration",
            component: Configuration
        },
        {
            path: "/signout",
            name: "signout",
            component: SignOut
        },
        {
            path: "/profile",
            name: "profile",
            components: Profile
        }
    ]
});