<template>
  <div id="wrapper">
    <div id="stream">
      <VueTwitchPlayer :channel="datos[number].channel"></VueTwitchPlayer>
    </div>

    <div id="Streams" class="my-auto py-auto">
      <v-container fluid>
        <v-row>
          <v-col cols="12">
            <v-row
              align="center"
              justify="space-around"
              class="grey lighten-5"
              style="height: 300px;"
            >
              <v-card
                v-for="videos in datos"
                :key="videos.title"
                class="ma-3 pa-6"
                outlined
                tile
              >
                {{ videos.title }}
                <br />
                canal: {{ videos.channel }}
                <VueTwitchPlayer :channel="videos.channel"></VueTwitchPlayer>
              </v-card>
            </v-row>
          </v-col>
        </v-row>
      </v-container>
    </div>
  </div>
</template>

<script>
import VueTwitchPlayer from "vue-twitch-player";

export default {
  components: {
    VueTwitchPlayer
  },
  data() {
    return {
      datos: [
        {
          title: "RiotGames",
          channel: "riotgames",
          descripcion: "Canal oficial de Riotgames"
        },
        {
          title: "OverwatchLeague",
          channel: "overwatchleague",
          descripcion: "Canal oficial de Overwatch"
        },
        {
          title: "PokémonLeague",
          channel: "pokemon",
          descripcion: "Canal oficial de Pokémon"
        },
        {
          title: "CSGO League",
          channel: "esl_csgo",
          descripcion: "Canal oficial de Counter Strike"
        },
        {
          title: "The international",
          channel: "dota2ti",
          descripcion: "Canal oficial de Dota 2"
        },
        {
          title: "Fortnite",
          channel: "fortnite",
          descripcion: "Canal oficial de Fortnite"
        },
        {
          title: "Faker",
          channel: "faker",
          descripcion: "Canal oficial de Faker"
        },
        {
          title: "Mata",
          channel: "mata",
          descripcion: "Canal oficial de Mata"
        },
        {
          title: "Sneaky",
          channel: "sneaky",
          descripcion: "Canal oficial de Sneaky"
        }
      ],
      min: 0,
      max: 5,
      number: 3
    };
  },
  created: function() {
    this.getRandomNumber();
  },
  methods: {
    loadNum: function() {
      this.min = 1;
      this.max = 10;
      this.getRandomNumber();
    },
    getInput: function() {
      let min = Number(this.min);
      let max = Number(this.max);
      if (min > max) {
        [min, max] = [max, min];
      }
      this.min = min;
      this.max = max;
      this.getRandomNumber();
    },
    getRandomNumber: function() {
      this.number = this.generateNumber();
    },
    generateNumber: function() {
      return Math.floor(Math.random() * (this.max - this.min + 1) + this.min);
    }
  }
};
</script>

<style type="text/css">
html,
body {
  height: 100%;
  margin: 0;
}

#stream iframe {
  width: 100%;
  height: 500px;
}

#Steams iframe {
  width: 200px;
  height: 150px;
}
</style>
