import Vue from "vue";
import App from "./App.vue";
import vuetify from "./plugins/vuetify";
import router from "./router";
import LoadScript from "vue-plugin-load-script";
import firebase from "firebase";

Vue.config.productionTip = false;

const firebaseConfig = {
    apiKey: "AIzaSyB8GpbTvWoicv-atxjgyl9x_bLINQUx298",
    authDomain: "adoo-final.firebaseapp.com",
    databaseURL: "https://adoo-final.firebaseio.com",
    projectId: "adoo-final",
    storageBucket: "adoo-final.appspot.com",
    messagingSenderId: "665450509994",
    appId: "1:665450509994:web:eb7110206d675ad58e42d3",
    measurementId: "G-Z23PCD25J1"
};

firebase.initializeApp(firebaseConfig);

new Vue({
    vuetify,
    router,
    render: h => h(App),
}).$mount("#app");

Vue.use(LoadScript);