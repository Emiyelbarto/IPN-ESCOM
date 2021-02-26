<template>
  <div
    class="flex justify-center align-middle content-center bg-gray-300 h-screen"
  >
    <div class="px-3 my-32 shadow-lg rounded-lg w-full max-w-lg bg-white">
      <form>
        <div
          class="text-2xl capitalize tracking-wide text-gray-700 font-bold mb-5 rounded-lg py-4"
        >
          Modificar lugar de compra
        </div>
        <div class="flex flex-wrap -mx-3">
          <div class="w-full  px-3 mb-6 md:mb-0">
            <label
              class="block capitalize tracking-wide text-gray-700 text-xl font-bold mb-2"
              for="nombre"
            >
              Nombre
            </label>
            <input
              id="nombre"
              class="block w-full bg-gray-200 text-gray-700 border rounded py-3 px-4 mb-3 leading-tight focus:outline-none focus:bg-white text-xl"
              type="text"
              placeholder=""
            />
          </div>
        </div>
        <label
          class="block capitalize tracking-wide text-gray-700 text-xl font-bold mb-2"
          for="calle"
        >
          Dirección
        </label>
        <div class="flex flex-wrap -mx-3">
          <div class="w-full  px-3 mb-6 md:mb-0">
            <input
              id="calle"
              class="appearance-none block w-full bg-gray-200 text-gray-700 border rounded py-3 px-4 mb-3 leading-tight focus:outline-none focus:bg-white text-lg"
              type="text"
              placeholder=""
            />
          </div>
        </div>
        <div class="flex content-center justify-center">
          <button
            class="mx-2 bg-blue-500 hover:bg-blue-700 text-white font-bold py-3 px-4 rounded focus:outline-none focus:shadow-outline  w-2/3"
          >
            Guardar
          </button>
          <button
            class="mx-2 text-blue-500 hover:text-blue-700 border border-blue-500 hover:border-blue-700 font-bold py-3 px-4 rounded focus:outline-none focus:shadow-outline w-2/3"
          >
            Regresar
          </button>
        </div>
      </form>
    </div>
  </div>
</template>

<script>
export default {}
</script>

<style></style>
