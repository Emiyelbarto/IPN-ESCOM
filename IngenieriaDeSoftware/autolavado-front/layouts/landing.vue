<template>
  <div>
    <perfect-scrollbar>
      <a-navbar />
      <main>
        <nuxt />
      </main>
      <a-footer />
    </perfect-scrollbar>
  </div>
</template>

<script>
import ANavbar from '~/components/landing/ANavBar'
import AFooter from '~/components/landing/AFooter'
export default {
  components: {
    ANavbar,
    AFooter
  }
}
</script>
