<template>
  <div>
    <navBar />
    <headerArea />
    <spacerSect />
    <teamSect />
    <servSect />
    <!-- <workSect /> -->
    <contact-sect />
    <foooter />
    <scroll-up />
  </div>
</template>
<script src="/js/jquery.js"></script>
<script src="~/static/js/jquery.scrollTo.js"></script>
<script src="~/static/js/jquery.nav.js"></script>
<script src="~/static/js/jquery.localScroll.js"></script>
<script src="~/static/js/bootstrap.js"></script>
<script src="~/static/js/jquery.prettyPhoto.js"></script>
<script src="~/static/js/isotope.js"></script>
<script src="~/static/js/jquery.flexslider.js"></script>
<script src="~/static/js/inview.js"></script>
<script src="~/static/js/animate.js"></script>
<script src="~/static/js/custom.js"></script>
<script src="~/static/contactform/contactform.js"></script>

<script>
import ANavbar from '~/components/landing/ANavBar'
import headerArea from '~/components/landing/headerArea.vue'
import spacerSect from '~/components/landing/spacerSection.vue'
import teamSect from '~/components/landing/teamSection.vue'
import servSect from '~/components/landing/servicesSection.vue'
import workSect from '~/components/landing/worksSect.vue'
import contactSect from '~/components/landing/contactSection.vue'
import foooter from '~/components/landing/foooter.vue'
import scrollUp from '~/components/landing/scrollUp.vue'
export default {
  components: {
    ANavbar,
    headerArea,
    spacerSect,
    teamSect,
    servSect,
    workSect,
    contactSect,
    foooter,
    scrollUp
  }
}
</script>

<style></style>
