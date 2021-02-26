<template>
  <div>
    <section id="banner-paquetes">
      <div>
        <img src="" alt="" />
      </div>
    </section>
    <section id="seccion-paquetes"></section>
    <section id="seccion-pago"></section>
    {{ paquetes }}
  </div>
</template>

<script>
export default {
  layout: 'landing',
  computed: {
    paquetes() {
      return this.$store.state.landing.paquetes.data
    },
    totalPages() {
      return this.$store.state.landing.paquetes.totalPages
    },
    currentPage: {
      get() {
        return this.$store.state.landing.paquetes.currentPage
      },

      set(value) {
        const queryParams = `?page=${value}`
        this.getPaquetes(queryParams)
      }
    }
  },
  async mounted() {
    try {
      await Promise.all([this.getPaquetes('')])
    } catch (error) {
      console.error(error)
    }
  },
  beforeDestroy() {
    this.$store.commit('landing/paquetes/SET_CURRENT_PAGE', 1)
  },
  methods: {
    getPaquetes(queryParams) {
      return this.$store.dispatch('landing/paquetes/getData', queryParams)
    }
  }
}
</script>
