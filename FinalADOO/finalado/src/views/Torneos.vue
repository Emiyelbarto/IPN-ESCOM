<template>
  <v-container class="pb-12 mb-12">
    <v-layout
      row
      wrap
      v-for="dato in datos"
      :key="dato.jugador"
      class="fill-height"
    >
      <v-flex xs12 sm6 class="my-auto py-auto">
        <button to:datos.linkStream>
          <p v-html="dato.idFoto" />
        </button>
      </v-flex>
      <v-divider></v-divider>
      <v-flex x12 sm6 class="py-auto my-auto">
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
          juego: "LOL",
          nombre: "League of legends",
          idFoto:
            "<img src='https://www.esportspedia.com/lol/thumb.php?f=WorldsPlayerList.png&width=200'/>",
          linkStream: "https://www.twitch.tv/riotgames",
          descripcion:
            "Existen multitud de ligas y torneos de League of Legends, algunos organizados por Riot Games, otros por terceros con respaldo oficial, y otros independientes. Aquellos organizados o con respaldo oficial de Riot Games podrían resumirse en el Torneo Mundial, para el que se clasifican los mejores equipos de cada continente; los torneos de Tier 1, en los que se deciden los equipos de cada región que irán al mundial (como la LCS en Europa); y los torneos nacionales de Tier 2, que dependiendo de la región/continente, pueden tener categoría Challenger para promocionar a la Tier 1 (como la League of Legends Challenger de Corea) o puntuar para torneos independientes (como la SLO de España, que permite aspirar a participar en la European Masters)."
        },
        {
          juego: "Dota 2",
          nombre: "Defense Of The Ancients 2",
          idFoto:
            "<img src='https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcSvIaIAjMWAJDXHkEIqO-V4FmfE64yNp74D_mT_Z7TSGDnL3r8Q'/>",
          linkStream: "dotati",
          descripcion:
            "Dota 2 (abreviatura de Defense of the Ancients 2 y en Español Defensa de los Ancestros 2) es un videojuego perteneciente al género de Arena de batalla en línea ARTS («estrategia de acción en tiempo real»), también conocido como MOBA, lanzado el 9 de julio del año 2013. El juego fue desarrollado por la empresa Valve Corporation. El título fue anunciado oficialmente el 13 de octubre de 2010, en un artículo en el sitio web Game Informer;​ posteriormente, entró en su etapa Beta a principios del 2011, y finalmente se lanzó al público en general a través de Steam el 9 de julio de 2013 para Microsoft Windows, y el 18 de julio de 2013 para OS X y Linux, el 17 de junio de 2015 Valve lanzó la beta del juego usando el nuevo motor gráfico Source 2 [Dota 2 Reborn], cliente que será el único y definitivo poco después del The International 2015 según el anuncio se mantuvo fiel a su predecesor, a la vez que incrementó la calidad del producto final, además de ofrecer una experiencia envolvente y gratificante para los jugadores. Sin embargo Dota 2 es actualmente criticado por tener una dura curva de aprendizaje y una comunidad de las más hostiles en el ámbito de internet. Actualmente es el juego más jugado de Steam con más de 40.6 millones de jugadores​ únicos que se conectan casi en su totalidad con frecuencia diaria​ y ha llegado a ser incluido en el Guinness World Records Gamer's Edition."
        },
        {
          juego: "SMITE",
          nombre: "Defense Of The Ancients 2",
          idFoto:
            "<img src='http://assets.stickpng.com/thumbs/5905fcef0cbeef0acff9a627.png'/>",
          linkStream: "smite",
          descripcion:
            "SMITE es un videojuego de acción MOBA en tercera persona, creado y publicado por Hi-Rez Studios para Microsoft Windows, MAC, Xbox One, PlayStation 4 y Nintendo Switch. El juego se basa en dos equipos, cada uno formado por cinco dioses, enfrentados en un campo de batalla con la finalidad de destruir el titán enemigo situado en cada una de las bases. Cada jugador se pone en la piel de un dios de diferentes mitologías el cual posee distintos poderes y características. En el campo de batalla también se pueden encontrar personajes no controlados (súbditos) que proporcionan oro y experiencia."
        },
        {
          juego: "Rainbow six Siege",
          nombre: "Rainbow Six Siege",
          idFoto:
            "<img src='https://upload.wikimedia.org/wikipedia/commons/a/a2/Rainbow_Six_siege_photo_2014-06-14_17-51.jpg'/>",
          linkStream: "rainbowsixsiege",
          descripcion:
            "Tom Clancy's Rainbow Six: Siege es un videojuego de disparos en primera persona táctico multijugador de 5 vs 5 en el cual hay 3 modos de juego, 'Desactivar la bomba', 'Capturar el objetivo' y 'Protección del rehén', también tiene 7 modos de juego, está desarrollado por la empresa Ubisoft Montreal y distribuido por Ubisoft para las plataformas PlayStation 4, Xbox One y Microsoft Windows. El juego fue anunciado en la conferencia de E3 en junio de 20141​ y, tras ser retrasado, su fecha de lanzamiento se produjo el 1 de diciembre de 2015."
        }
      ]
    };
  }
};
</script>

<style lang="scss">
img {
  width: 200px;
}
</style>
