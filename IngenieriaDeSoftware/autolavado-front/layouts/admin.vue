<template>
  <div>
    <perfect-scrollbar />
    <a-sidebar />
    <main>
      <nuxt />
    </main>
  </div>
</template>

<script>
import ASidebar from '~/components/admin/ASidebar'
export default {
  components: {
    ASidebar
  }
}
</script>
