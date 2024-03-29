<?php
// $Id$

?>
<div id="node-<?php print $node->nid; ?>" class="worx-node-<?php print $node->type; ?>"><div class="node-inner">

  <?php print $picture; ?>

  <?php if (!$page): ?>
    <h2 class="title">
      <a href="<?php print $node_url; ?>" title="<?php print $title ?>"><?php print $title; ?></a>
    </h2>
  <?php endif; ?>

  <?php if ($unpublished): ?>
    <div class="unpublished"><?php print t('Unpublished'); ?></div>
  <?php endif; ?>
  <h3><?php print $field_worx_news_tagline[0]['value']; ?></h3>
  <?php if ($submitted || $terms): ?>
    <div class="meta">
      <?php if ($submitted): ?>
        <div class="submitted">
          <?php print $submitted; ?>
        </div>
      <?php endif; ?>

      <?php if ($terms): ?>
        <div class="terms terms-inline"><?php print t(' in ') . $terms; ?></div>
      <?php endif; ?>
    </div>
  <?php endif; ?>

  <div class="content clear-block">
    <?php if ($field_worx_news_photo[0]['fid']): ?>
    <?php print '<div class="worx_news_photo">'. $field_worx_news_photo[0]['view'] .'</div>'; ?>
    <?php endif; ?>
    <?php print $content; ?>
  </div>

  <?php print $links; ?>

</div></div> <!-- /node-inner, /node -->
