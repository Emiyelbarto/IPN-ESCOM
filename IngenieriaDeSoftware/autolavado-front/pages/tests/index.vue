<template lang="html">
  <div class="examplex">
    <vs-dropdown>
      <a class="a-icon" href="#">
        Dropdown hover
        <vs-icon class="" icon="expand_more"></vs-icon>
      </a>

      <vs-dropdown-menu>
        <vs-dropdown-item>
          Option 1
        </vs-dropdown-item>
        <vs-dropdown-item>
          Option 2
        </vs-dropdown-item>
        <vs-dropdown-item divider>
          Option 3
        </vs-dropdown-item>
      </vs-dropdown-menu>
    </vs-dropdown>

    <vs-dropdown>
      <a class="a-icon" href.prevent>
        Dropdown Option Disabled
        <vs-icon class="" icon="expand_more"></vs-icon>
      </a>

      <vs-dropdown-menu>
        <vs-dropdown-item>
          Option 1
        </vs-dropdown-item>
        <vs-dropdown-item disabled>
          Option 2
        </vs-dropdown-item>
        <vs-dropdown-item disabled divider>
          Option 3
        </vs-dropdown-item>
      </vs-dropdown-menu>
    </vs-dropdown>
  </div>
</template>

<script>
export default {
  computed: {
    paquetes() {
      return this.$store.state.admin.paquetes.data
    }
  },
  methods: {
    getPaquetes() {
      this.$store.dispatch('/admin/paquetes/getPaquetes')
    }
  }
}
</script>
