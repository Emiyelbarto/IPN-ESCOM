<template>
  <div class="home">
    <AParallax />
    <CParallax />
    <BParallax />
  </div>
</template>

<script>
import AParallax from "../components/AParallax.vue";
import BParallax from "../components/BParallax.vue";
import CParallax from "../components/CParallax.vue";
export default {
  components: {
    AParallax,
    BParallax,
    CParallax
  }
};
</script>

<style></style>
