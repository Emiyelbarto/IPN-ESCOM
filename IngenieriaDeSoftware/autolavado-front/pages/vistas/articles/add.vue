<template>
  <div
    class="flex justify-center align-middle content-center bg-gray-300 h-screen"
  >
    <div class="px-3  my-16 rounded-lg w-full max-w-lg bg-white">
      <form>
        <div
          class="text-2xl capitalize tracking-wide text-gray-500 font-bold mb-5 rounded-lg py-4"
        >
          Agregar articulo
        </div>
        <div class="flex flex-wrap -mx-3">
          <div class="w-full  px-3 mb-6 md:mb-0">
            <label
              class="block capitalize tracking-wide text-gray-500 text-xl font-bold mb-2"
              for="nombre"
            >
              Nombre
            </label>
            <input
              id="nombre"
              class="block w-full bg-gray-200 text-gray-500 border rounded py-3 px-4 mb-3 leading-tight focus:outline-none focus:bg-white text-xl"
              type="text"
              placeholder=""
            />
          </div>
          <div class="md:flex md:items-center mb-6 w-full px-3">
            <div class="md:w-1/3">
              <label
                class="block text-gray-500 font-bold md:text-right mb-1 md:mb-0 pr-4"
                for="precio"
              >
                Precio
              </label>
            </div>
            <div class="md:w-2/3">
              <input
                id="precio"
                class="bg-gray-200 appearance-none border-2 border-gray-200 rounded w-full py-2 px-4 text-gray-500 leading-tight focus:outline-none focus:bg-white focus:border-purple-500"
                type="text"
                value="0.00"
              />
            </div>
          </div>
          <div class="md:flex md:items-center mb-6 w-full px-3">
            <div class="md:w-1/3">
              <label
                class="block text-gray-500 font-bold md:text-right mb-1 md:mb-0 pr-4"
                for="cantidad"
              >
                Cantidad
              </label>
            </div>
            <div class="md:w-2/3">
              <input
                id="cantidad"
                class="bg-gray-200 appearance-none border-2 border-gray-200 rounded w-full py-2 px-4 text-gray-500 leading-tight focus:outline-none focus:bg-white focus:border-purple-500"
                type="text"
                value="1"
              />
            </div>
          </div>
          <div class="md:flex md:items-center mb-6 w-full px-3">
            <div class="md:w-1/3">
              <label
                class="block text-gray-500 font-bold md:text-right mb-1 md:mb-0 pr-4"
                for="codigodebarras"
              >
                Codigo de Barras
              </label>
            </div>
            <div class="md:w-2/3">
              <input
                id="codigodebarras"
                class="bg-gray-200 appearance-none border-2 border-gray-200 rounded w-full py-2 px-4 text-gray-500 leading-tight focus:outline-none focus:bg-white focus:border-purple-500"
                type="text"
                value=""
              />
            </div>
          </div>
          <div class="md:flex md:items-center mb-6 w-full px-3">
            <div class="md:w-1/3">
              <div
                class="block text-gray-500 font-bold md:text-right mb-1 md:mb-0 pr-4"
                for="lugardecompra"
              >
                Lugar de Compra
              </div>
            </div>
            <div class="md:w-2/3">
              <select
                id="lugardecompra"
                class="bg-gray-200 appearance-none border-2 border-gray-200 rounded w-full py-2 px-4 text-gray-500 leading-tight focus:outline-none focus:bg-white focus:border-purple-500"
                type="text"
                value=""
              >
                <option>Seleccione una opcion</option>
              </select>
            </div>
          </div>
          <div class="md:flex md:items-center mb-6 w-full px-3">
            <div class="md:w-1/3">
              <label
                class="block text-gray-500 font-bold md:text-right mb-1 md:mb-0 pr-4"
                for="Descripción"
              >
                Descripción
              </label>
            </div>
            <div class="md:w-2/3">
              <input
                id="Descripción"
                class="bg-gray-200 appearance-none border-2 border-gray-200 rounded w-full py-2 px-4 text-gray-500 leading-tight focus:outline-none focus:bg-white focus:border-purple-500"
                type="text"
                value=""
              />
            </div>
          </div>
          <div class="flex content-center justify-center w-full">
            <button
              class="mx-2 bg-blue-500 hover:bg-blue-700 text-white font-bold py-3 px-4 rounded focus:outline-none focus:shadow-outline  w-2/3"
            >
              Agregar
            </button>
            <button
              class="mx-2 text-blue-500 hover:text-blue-700 border border-blue-500 hover:border-blue-700 font-bold py-3 px-4 rounded focus:outline-none focus:shadow-outline w-2/3"
            >
              Regresar
            </button>
          </div>
        </div>
      </form>
    </div>
  </div>
</template>

<script>
export default {}
</script>

<style></style>
