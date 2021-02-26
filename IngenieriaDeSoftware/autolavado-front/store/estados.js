export const state = () => ({
  estados: []
})

export const actions = {
  async getAll({ commit, state }) {
    try {
      if (state.estados.length > 0) return

      const { data } = await this.$axios.get('/estados')

      commit('SET_ESTADOS', data)
    } catch (error) {
      // eslint-disable-line no-console
      console.error(error)
    }
  }
}

export const mutations = {
  SET_ESTADOS(state, estados) {
    state.estados = estados
  },
  CLEAN_DATA(state) {
    state.estados = []
  }
}
