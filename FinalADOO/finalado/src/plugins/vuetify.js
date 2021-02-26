import Vue from 'vue';
import Vuetify from 'vuetify/lib';

Vue.use(Vuetify);

export default new Vuetify({
    iconfont: 'mdi',
    theme: {
        primary: '#000080',
        success: 'indigo',
        info: '#C0C0C0',
        error: 'D92121'
    }
});