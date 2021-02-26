<template>
  <div>
    <div class="tablas--contenido">
      <vs-table>
        <template slot="header">
          <h3>Administracion del sitio</h3>
        </template>
        <template slot="thead">
          <vs-th>Autorizacion</vs-th>
          <vs-th>Accion</vs-th>
        </template>
        <template>
          <vs-tr>
            <vs-td v-for="(n, index) in 4" :key="index">data</vs-td>
          </vs-tr>
        </template>
      </vs-table>
      <h1>
        Administración del sitio
      </h1>
      <h2>
        Autentificación y Autorización
      </h2>
      <table>
        <colgroup>
          <col style="width: 10%" />
          <col style="width: 40%" />
          <col style="width: 10%" />
        </colgroup>
        <tr>
          <th>
            <vs-button
              :active="active"
              size="small"
              to="/Login"
              @click="activar"
              >Grupos</vs-button
            >
          </th>
          <td></td>
          <td>
            <vs-button
              :active="active"
              color="dark"
              type="flat"
              size="small"
              to="/Login"
              @click="activar"
              >Agregar</vs-button
            >
          </td>
        </tr>
        <tr>
          <th>
            <vs-button
              :active="active"
              size="small"
              to="/Login"
              @click="activar"
              >Usuarios</vs-button
            >
          </th>
          <td></td>
          <td>
            <vs-button
              :active="active"
              color="dark"
              type="flat"
              size="small"
              to="/Login"
              @click="activar"
              >Agregar</vs-button
            >
          </td>
        </tr>
      </table>

      <br />
      <h2>
        Lavado
      </h2>

      <table>
        <colgroup>
          <col style="width: 10%" />
          <col style="width: 40%" />
          <col style="width: 10%" />
        </colgroup>
        <tr>
          <th>
            <vs-button
              :active="active"
              size="small"
              to="/Login"
              @click="activar"
              >Articulos</vs-button
            >
          </th>
          <td></td>
          <td>
            <vs-button
              :active="active"
              color="dark"
              type="flat"
              size="small"
              to="/AdministracionSitio/Articulo-Agregar"
              @click="activar"
              >Agregar</vs-button
            >
          </td>
        </tr>
        <tr>
          <th>
            <vs-button
              :active="active"
              size="small"
              to="/Login"
              @click="activar"
              >Empleados</vs-button
            >
          </th>
          <td></td>
          <td>
            <vs-button
              :active="active"
              color="dark"
              type="flat"
              size="small"
              to="/AdministracionSitio/Empleados-Agregar"
              @click="activar"
              >Agregar</vs-button
            >
          </td>
        </tr>
        <tr>
          <th>
            <vs-button
              :active="active"
              size="small"
              to="/Login"
              @click="activar"
              >Lugar de compras</vs-button
            >
          </th>
          <td></td>
          <td>
            <vs-button
              :active="active"
              color="dark"
              type="flat"
              size="small"
              to="/AdministracionSitio/LugarCompra-Agregar"
              @click="activar"
              >Agregar</vs-button
            >
          </td>
        </tr>
        <tr>
          <th>
            <vs-button
              :active="active"
              size="small"
              to="/Login"
              @click="activar"
              >Paquetes</vs-button
            >
          </th>
          <td></td>
          <td>
            <vs-button
              :active="active"
              color="dark"
              type="flat"
              size="small"
              to="/AdministracionSitio/Paquete-Agregar"
              @click="activar"
              >Agregar</vs-button
            >
          </td>
        </tr>
        <tr>
          <th>
            <vs-button
              :active="active"
              size="small"
              to="/Login"
              @click="activar"
              >Rol empleados</vs-button
            >
          </th>
          <td></td>
          <td>
            <vs-button
              :active="active"
              color="dark"
              type="flat"
              size="small"
              to="/Login"
              @click="activar"
              >Agregar</vs-button
            >
          </td>
        </tr>
      </table>
    </div>
  </div>
</template>

<script>
export default {
  methods: {
    layout: 'admin',
    data() {
      return {
        active: false
      }
    },
    activar() {
      this.active = !this.active
    }
  }
}
</script>
