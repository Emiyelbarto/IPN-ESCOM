<template>
  <section id="contact" class="section green">
    <div class="container">
      <h4>Contactanos</h4>
      <p>
        Estamos comprometidos con nustros clientes y a la mejora continua <br />
        Apreciamos tu retroalimentación
      </p>
      <div class="blankdivider30"></div>
      <div class="row">
        <div class="span12">
          <div id="contact-form" class="cform">
            <div id="sendmessage">Tu mensaje fue enviado</div>
            <div id="errormessage"></div>
            <form action="" method="post" role="form" class="contactForm">
              <div class="row">
                <div class="span6">
                  <div class="field your-name form-group">
                    <input
                      id="name"
                      type="text"
                      name="name"
                      class="form-control"
                      placeholder="Nombre"
                      data-rule="minlen:4"
                      data-msg="Please enter at least 4 chars"
                    />
                    <div class="validation"></div>
                  </div>
                  <div class="field your-email form-group">
                    <input
                      id="email"
                      type="text"
                      class="form-control"
                      name="email"
                      placeholder="e-mail"
                      data-rule="email"
                      data-msg="Please enter a valid email"
                    />
                    <div class="validation"></div>
                  </div>
                  <div class="field subject form-group">
                    <input
                      id="subject"
                      type="text"
                      class="form-control"
                      name="subject"
                      placeholder="Asunto"
                      data-rule="minlen:4"
                      data-msg="Please enter at least 8 chars of subject"
                    />
                    <div class="validation"></div>
                  </div>
                </div>
                <div class="span6">
                  <div class="field message form-group">
                    <textarea
                      class="form-control"
                      name="message"
                      rows="5"
                      data-rule="required"
                      data-msg="Please write something for us"
                      placeholder="Mensaje"
                    ></textarea>
                    <div class="validation"></div>
                  </div>
                  <input
                    type="submit"
                    value="Send message"
                    class="btn btn-theme pull-left"
                  />
                </div>
              </div>
            </form>
          </div>
        </div>
        <!-- ./span12 -->
      </div>
    </div>
  </section>
</template>

<script>
export default {}
</script>

<style></style>
