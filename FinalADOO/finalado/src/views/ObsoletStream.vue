<template>
  <div class="streamings">
    <v-app>
      <v-card class="mx-auto" max-width="30%" tile id="videos_list">
        <v-list-item v-for="video in videos" :key="video">
          <v-list-item-content>
            <v-list-item-title>{{ video.title }}</v-list-item-title>
            <div id="app">
              <twitch-player channel="riotgames" />
            </div>
          </v-list-item-content>
        </v-list-item>
      </v-card>
    </v-app>
  </div>
  <!--   
            <iframe
              src="https://player.twitch.tv/?video=v367046564&autoplay=true"
              frameborder="0"
            ></iframe> -->
</template>

<script src="https://player.twitch.tv/js/embed/v1.js"></script>
<script>
import VueTwitchPlayer from "vue-twitch-player";

export default {
  data() {
    return {
      videos: [
        {
          title: "vid1",
          text: "text1",
          url: "https://player.twitch.tv/?video=v367046564&autoplay=true"
        },
        {
          title: "vid2",
          text: "text2",
          url: "https://player.twitch.tv/?video=v367046564&autoplay=true"
        }
      ],
      channel: "riotgames"
    };
  },
  components: { VueTwitchPlayer }
};
</script>

<style></style>
