<template>
  <section id="contact" class="section">
    <div class="container">
      <h4>Agregar lugar de compra</h4>
      <div class="blankdivider30"></div>
      <div class="row text">
        <div class="span12">
          <div id="contact-form" class="cform">
            <form action="" method="post" role="form" class="contactForm">
              <div class="row ">
                <div class="span6 aligncenter">
                  <div class="field form-group">
                    <input
                      id="nombre"
                      type="text"
                      name="nombre"
                      placeholder="Nombre"
                      class="form-control"
                    />
                  </div>
                  <div class="field form-group">
                    <input
                      id="direccion"
                      type="text"
                      name="direccion"
                      placeholder="Dirección"
                      class="form-control"
                    />
                  </div>
                </div>
              </div>
              <input
                type="submit"
                value="Agregar lugar"
                class="btn btn-theme-blue pull-left"
              />
            </form>
          </div>
        </div>
      </div>
    </div>
  </section>
</template>

<script>
export default {}
</script>

<style>
body {
  background-color: lightgray;
}

section.section {
  padding: 0 0 0 0 !important;
}

.container {
  background-color: #f3f3f3 !important;
  padding: 3em;
  border-radius: 1em;
  box-shadow: 1em;
}
</style>
