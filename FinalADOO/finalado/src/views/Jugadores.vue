<template>
  <v-container class="grey lighten-5">
    <v-layout
      row
      wrap
      v-for="dato in datos"
      :key="dato.jugador"
      class="fill-height"
    >
      <v-flex xs12 sm6 class="pb-12 mb-12">
        <button class="my-auto py-auto">
          <v-img
            src="@/assets/pictures/userhombre.png"
            width="200px"
            class="mx-auto"
          >
          </v-img>
        </button>
      </v-flex>
      <v-divider></v-divider>
      <v-flex x12 sm6 class="my-auto py-auto">
        <p>{{ dato.descripcion }}</p>
      </v-flex>
    </v-layout>
  </v-container>
</template>

<script>
export default {
  data() {
    return {
      datos: [
        {
          juego: "DOTA 2",
          jugador: "KuroKy",
          nombre: "Kuro Salehi Takhasomi",
          edad: "27",
          equipo: "Nigma",
          rol: "Support/Capitán",
          idFoto: "@/assets/pictures/kuroki.jpg",
          descripcion:
            "La primera aparición pública de KuroKy en Dota 2 fue The International 2011 junto con el debut del juego en Gamescom. Participó en el torneo bajo GosuGamers.net con sus compañeros de equipo Kebap, Azen y Mirakel. Desafortunadamente para ellos, dejaron caer los tres juegos de la fase de grupos y fueron eliminados por MiTH."
        },
        {
          juego: "SSBU",
          jugador: "MKLeo",
          nombre: "Leonardo Lopez Perez",
          edad: "18",
          equipo: "NA",
          rol: "Joker Main",
          idFoto: "@/assets/pictures/Leo.jpg",
          descripcion:
            "Leonardo 'MKLeo' Lopez Perez or 'Leo' is an Ultimate Joker player, and a former Wii U top professional Cloud and Marth main, from Mexico. MKLeo is his country's best player and widely considered to be one of the best players in the world. He is ranked as the 3rd best Wii U player of all-time on the PGR100. With his first place ranking on the fifth iteration on the PGR it marked the first time a player was ranked 1st that was not ZeRo. Along with being the last player in Wii U history to be ranked number one, he started off Ultimate also being the number one player in the world. In Ultimate he is currently ranked 1st on PGRU Spring 2019."
        },
        {
          juego: "SMITE",
          jugador: "BaRRaCCuDDa",
          nombre: "John Salter",
          edad: "28",
          equipo: "Spacestation",
          rol: "Mid Laner",
          idFoto: "@/assets/pictures/Barracuda.png",
          descripcion:
            "BaRRaCCuDDa currently resides in Cartersville, Georgia. He and his siblings used to play video games on the Nintendo, GameCube, and Nintendo 64. This evolved into LAN parties on weekends with his friends. Competitive gaming was a pipe dream of his, a major interest for the young BaRRaCCuDDa who watched MLG tournaments for Halo 2 and Halo 3. He graduated from college in 2013 with a B.S. in Exercise and Health Science. After college, he didn't have a job, allowing a smooth transition to competitive gaming in Halo: Reach, competing in MLG Columbus 2012 for the team Crystal Clear. He learned about SMITE, soon becoming one of the first competitive SMITE players."
        },
        {
          juego: "Rainbow six Siege",
          jugador: "Kendrew",
          nombre: "Luke Kendrew",
          edad: "20",
          equipo: "Natus Vincere",
          rol: "Control",
          idFoto: "@/assets/pictures/Kendrew.jpg",
          descripcion:
            "Luke 'Kendrew' Kendrew (born March 27, 1999) is a British Rainbow Six Siege currently playing for Natus Vincere."
        },
        {
          juego: "Overwatch league",
          jugador: "super",
          nombre: "Matthew DeLisi",
          edad: "19",
          equipo: "Quavo",
          rol: "Tanque",
          idFoto: "<img src='@/assets/pictures/Super.png'>",
          descripcion:
            "Matthew super DeLisi is an American Main Tank player, who currently plays for San Francisco Shock in the Overwatch League."
        }
      ]
    };
  }
};
</script>

<style></style>
