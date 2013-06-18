(function ($) {

  Drupal.behaviors.promoCycle = {
    attach: function (context, settings) {
      $('.front ul.promo-items').carouFredSel({
        scroll: {
          fx: "crossfade"
        }
      });
    }
  };
  

})(jQuery);